//
// Created by lishc on 3/31/2023.
//

#ifndef LAB3_POINT_H
#define LAB3_POINT_H


class Point{
private:
    double x, y, z;
    double vx, vy,vz;
public:
    double getX(){return x;}
    double getY(){return y;}
    double getZ(){return z;}
    double getVx(){return vx;}
    double getVy(){return vy;}
    double getVz(){return vz;}
    Point(){}
    Point(double x_, double y_, double z_, double vx_,double vy_, double vz_){
        this->x = x_; this->z = z_; this->y = y_;
        this->vx = vx_; this->vy=vy_;this->vz=vz_;
    }

    void printPoint(){
        fflush(stdin);
        std::cout << "x: " << x << " y: " << y << " z: " << z << " vx: " << vx << " vy: " << vy << " vz: " << vz << std::endl;
    }
};
#endif //LAB3_POINT_H
