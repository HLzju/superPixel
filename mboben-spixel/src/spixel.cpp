/*
    ===== DESCRIPTION =====

    This is an implementation of the algorithms in

    Real-Time Coarse-to-fine Topologically Preserving Segmentation
    by Jian Yao, Marko Boben, Sanja Fidler, Raquel Urtasun

    published in CVPR 2015.

    http://www.cs.toronto.edu/~urtasun/publications/yao_etal_cvpr15.pdf

    Code is available from https://bitbucket.org/mboben/spixel

    ===== LICENSE =====

    Copyright(C) 2015  Jian Yao, Marko Boben, Sanja Fidler and Raquel Urtasun

    This program is free software : you can redistribute it and / or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/


#include "stdafx.h"
#include "segengine.h"
#include "functions.h"
#include "utils.h"
#include <fstream>
#include <cstdlib>
//#include "contrib/SGMStereo.h"

using namespace cv;
using namespace std;


int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        cout<<"Usage:"<<endl;
        cout<<"spixel inputImagePath  outputSuperPixelPath"<<endl;
        return 0;
    }
    Mat image = imread(argv[1]);
    
    SPSegmentationParameters params;
    params.superpixelNum = 300;
    params.appWeight = 1.0;
    params.regWeight = 1.0;
    params.lenWeight = 1.0;
    params.sizeWeight = 1.0;
    params.batchProcessing = 0;
    
    SPSegmentationEngine engine(params, image);
    
    engine.ProcessImage();
    
    imwrite(argv[2], engine.GetSegmentedImage());

    
  
    return 0;
}

