/*************************************************************************************
//
//  LICENSE INFORMATION
//
//  BCreator(tm)
//  Software for the control of the 3D Printer, "B9Creator"(tm)
//
//  Copyright 2011-2012 B9Creations, LLC
//  B9Creations(tm) and B9Creator(tm) are trademarks of B9Creations, LLC
//
//  This file is part of B9Creator
//
//    B9Creator is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    B9Creator is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with B9Creator .  If not, see <http://www.gnu.org/licenses/>.
//
//  The above copyright notice and this permission notice shall be
//    included in all copies or substantial portions of the Software.
//
//    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
//    LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
//    OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
//    WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
*************************************************************************************/

#include "slicecontext.h"
#include "../OS_GL_Wrapper.h"
#include "b9layoutprojectdata.h"
#include <QPoint>
#include <QVector2D>


SliceContext::SliceContext(QWidget *parent, B9LayoutProjectData *pmain) : QOpenGLWidget(parent)
{
    projectData = pmain;
    pSlice = NULL;
    // No need for setAutoBufferSwap in Qt6

}
SliceContext::~SliceContext()
{
}

QPixmap SliceContext::renderPixmap()
{
    // Create a QPixmap from the current OpenGL context
    return grab();
}




void SliceContext::SetSlice(Slice* slice)
{
	pSlice = slice;
}



void SliceContext::initializeGL()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_BLEND);

    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);

    glViewport(0, 0, projectData->GetResolution().x(), projectData->GetResolution().y());
    glMatrixMode(GL_PROJECTION);
    // TODO: Replace with RHI orthographic projection
    // gluOrtho2D(-projectData->GetBuildSpace().x()/2.0,
    //            projectData->GetBuildSpace().x()/2.0,
    //            -projectData->GetBuildSpace().y()/2.0,
    //            projectData->GetBuildSpace().y()/2.0);
    // For now, set up basic orthographic projection manually
    glLoadIdentity();
    float left = -projectData->GetBuildSpace().x()/2.0f;
    float right = projectData->GetBuildSpace().x()/2.0f;
    float bottom = -projectData->GetBuildSpace().y()/2.0f;
    float top = projectData->GetBuildSpace().y()/2.0f;
    
    float orthoMatrix[16] = {
        2.0f/(right-left), 0, 0, 0,
        0, 2.0f/(top-bottom), 0, 0,
        0, 0, -2.0f/(1.0f-(-1.0f)), 0,
        -(right+left)/(right-left), -(top+bottom)/(top-bottom), -1.0f-(-1.0f)/(1.0f-(-1.0f)), 1
    };
    glMultMatrixf(orthoMatrix);
	glMatrixMode(GL_MODELVIEW);
}

void SliceContext::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();//重置矩阵运算
	
	if(pSlice)
	{
        pSlice->Render();
	}

}




