#ifndef DISTANCE_FORMATION_HH
#define DISTANCE_FORMATION_HH 1

#include <Eigen/Dense>
#include <Eigen/Sparse>

class DistanceFormation
{
    private:
        // Rigid formation
        int _m;
        float _l;

        Eigen::MatrixXf _B;
        Eigen::MatrixXf _S1;
        Eigen::MatrixXf _S2;
        Eigen::MatrixXf _Av;
        Eigen::MatrixXf _Aa;
        Eigen::MatrixXf _Bb;
        Eigen::MatrixXf _S1b;
        Eigen::MatrixXf _S2b;
        Eigen::MatrixXf _Avb;
        Eigen::MatrixXf _Aab;

        Eigen::VectorXf _d;
        int _agents, _edges;
        Eigen::VectorXf _mu;
        Eigen::VectorXf _tilde_mu;

        float _c_shape, _c_vel;

        void _make_S1_S2();
        void _make_Av_Aa();
        Eigen::MatrixXf _make_Dz(Eigen::VectorXf);
        Eigen::MatrixXf _make_Dzt(Eigen::VectorXf);
        Eigen::MatrixXf _make_Dzh(Eigen::VectorXf);
        Eigen::VectorXf _make_E(Eigen::VectorXf);

    public:
        DistanceFormation(int, int, Eigen::VectorXf, Eigen::VectorXf,
                Eigen::VectorXf, Eigen::MatrixXf, float, float);
        DistanceFormation();
        ~DistanceFormation();

        void set_mus(Eigen::VectorXf, Eigen::VectorXf);
        Eigen::VectorXf get_u_acc(Eigen::VectorXf, Eigen::VectorXf);
        Eigen::VectorXf get_u_vel(Eigen::VectorXf);
};

#endif // DISTANCE_FORMATION_HH
