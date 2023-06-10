#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <pcl/point_types.h>  //PCL中支持的点类型头文件
#include <pcl/point_cloud.h>  //PCL中支持的点集合类型头文件
#include <pcl/io/pcd_io.h>    //pcd读写类相关的头文件
#include <pcl/visualization/cloud_viewer.h>

//-----------------------------vtk---------------------------------
#include <vtkRenderWindow.h>
#include <vtkAutoInit.h>
#include <QVTKOpenGLNativeWidget.h>
#include <vtkSmartPointer.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <QVTKOpenGLStereoWidget.h>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    pcl::PointCloud<pcl::PointXYZ>::Ptr PointCloud;
    pcl::PCLPointCloud2 cloud2;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;

    //点云名称
    std::vector<std::string> cloud_name{"0","1","2"};
    int point_size=1;


private slots:
    void on_act_CrreatPoint_triggered();

private:
    void InitialVTK();//初始化VTK

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
