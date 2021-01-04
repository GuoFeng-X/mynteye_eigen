#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace std;

int main(int argc, char **argv)
{

    Eigen::Matrix3d R_rl, R_il;
    R_rl << 0.99988758563995361, -0.00269234180450439, 0.01474761962890625, 0.00258028507232666, 0.99996757507324219, 0.00761389732360840, -0.01476764678955078, -0.00757503509521484, 0.99986219406127930;
    R_il << 0.99996651999999997, 0.00430873000000000, 0.00695718000000000, 0.00434878000000000, -0.99997400999999997, -0.00575128000000000, 0.00693222000000000, 0.00578135000000000, -0.99995926000000002;
    Eigen::Vector3d t_rl, t_il;
    t_rl << -119.38642120361328125, 0.00000000000000000, 0.00000000000000000;
    t_il << -47.77362000000000108, -2.23730999999999991, -1.60071000000000008;

    Eigen::Matrix3d R_lr = R_rl.inverse();
    Eigen::Vector3d t_lr = -R_rl.inverse()*t_rl;

    std::cout<<" R_lr: "<<R_lr<<std::endl;
    std::cout<<" t_lr: "<<t_lr.transpose()<<std::endl;


    Eigen::Isometry3d T_lr = Eigen::Isometry3d::Identity();
    T_lr.rotate(R_lr);
    T_lr.pretranslate(t_lr);

    Eigen::Isometry3d T_il = Eigen::Isometry3d::Identity();
    T_il.rotate(R_il);
    T_il.pretranslate(t_il);

    Eigen::Isometry3d T_ir = T_il*T_lr;
    std::cout<<" T_ir: "<< T_ir.matrix() <<std::endl;
    return 0;
}