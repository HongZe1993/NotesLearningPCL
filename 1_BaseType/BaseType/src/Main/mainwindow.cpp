#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <vtkOutputWindow.h>
#include <qstring.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitialVTK();
//    vtkOutputWindow::SetGlobalWarningDisplay(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::InitialVTK()
{
    auto renderer = vtkSmartPointer <vtkRenderer>::New();
    auto renderWindow =vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    renderWindow->AddRenderer(renderer);

    viewer.reset(new pcl::visualization::PCLVisualizer(renderer, renderWindow,"viewer", false));
    viewer->setupInteractor(ui->qvtkWidget->interactor(), ui->qvtkWidget->renderWindow());
    ui->qvtkWidget->setRenderWindow(viewer->getRenderWindow());
    //viewer->addPointCloud(cloud, "cloud");
    ui->qvtkWidget->update();

    PointCloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
    //cloud2.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
}



void MainWindow::on_act_CrreatPoint_triggered()
{

    //创建一个PointCloud<PointXYZ> bosst共享指针并进行实例化
    PointCloud->width = 1000;
    PointCloud->height = 1;
    PointCloud->is_dense = false;
    PointCloud->points.resize(PointCloud->width * PointCloud->height);
    //点云的高度宽度和稠密度



    for(auto i = 1; i < 1000; i++)
    {
        //xyz
        PointCloud->points[i].x = 1024* rand()/(RAND_MAX + 1.0f);
        PointCloud->points[i].y = 1024* rand()/(RAND_MAX + 1.0f);
        PointCloud->points[i].z = 1024* rand()/(RAND_MAX + 1.0f);
    }


    pcl::io::savePCDFile("test_savePCDFile.pcd",*PointCloud);
    pcl::io::savePCDFileASCII("test_savePCDFileASCII.pcd",*PointCloud);
    pcl::io::savePCDFileBinary("test_savePCDFileBinary.pcd",*PointCloud);
    pcl::io::savePCDFileBinaryCompressed("test_savePCDFileBinaryCompressed.pcd",*PointCloud);


    //移除窗口点云
    viewer->removeAllPointClouds();
    viewer->removeAllShapes();
    //pcl::fromPCLPointCloud2<pcl::PointXYZ>(cloud2,*PointCloud);
    viewer->addPointCloud(PointCloud,cloud_name[0]);
    //viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, point_size, cloud_name[0]);
    viewer->resetCamera();
    ui->qvtkWidget->update();
}


//    //移除窗口点云
//    viewer->removeAllPointClouds();
//    viewer->removeAllShapes();
//    pcl::fromPCLPointCloud2<pcl::PointXYZ>(cloud2,*cloud);
//    viewer->addPointCloud(cloud,cloud_name[0]);
//    //viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, point_size, cloud_name[0]);
//    viewer->resetCamera();
//    ui->qvtkWidget->update();
//}

//void MainWindow::CreateCloudFromTxt(const std::string& file_path, pcl::PointCloud<pcl::PointXYZ>::Ptr cloud)
//{
//    std::ifstream file(file_path.c_str());
//    std::string line;
//    pcl::PointXYZ point;
//    //float nx, ny, nz;
//    while (getline(file, line)) {
//        std::stringstream ss(line);
//        ss >> point.x;
//        ss >> point.y;
//        ss >> point.z;
//        //ss >> nx;
//        //ss >> ny;
//        //ss >> nz;
//        cloud->push_back(point);
//    }
//    file.close();
//}


