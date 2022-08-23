#include <ros/ros.h>
#include <std_msgs/UInt16MultiArray.h>
#include <geometry_msgs/PointStamped.h>

int main( int argc, char** argv )
{
    ros::init(argc,argv,"pwm_thrust_calib");
    ros::NodeHandle n;
    ros::NodeHandle pnh("~");

    ros::Publisher pwm16_pub = n.advertise<std_msgs::UInt16MultiArray>("/serial/pwm",1);
    ros::Publisher pwm_pub = n.advertise<geometry_msgs::PointStamped>("/pwm_desired",1);

    double rate = 100.0;
    double DT = 1.0/rate;
    double t_duration = 0.0;
    ros::Rate r(rate);
    double t_now = 0.0;

    bool pwm_end_flag = false;
    bool pwm_update_flag = true;
    
    int pwm_val_down = 2030; // 360 ~ 420, (0~4095)
    int pwm_val_up = 2030;

    while(ros::ok())
    {   
        if(t_now < 2.0)
        {
            pwm_val_down = 2030;
            pwm_val_up = 2030;
        }
        else if(t_now < 4.0)
        {
            pwm_val_down = 2030;
            pwm_val_up = 2030;
        }
        else
        {
            pwm_val_down = 2100;
            pwm_val_up = 2100;
        }
        // else if(t_now < 6.0)
        // {
        //     pwm_val_ = 2060;
        // }
        // else if(t_now < 8.0)
        // {
        //     pwm_val_ = 2048;
        // }
        // else if(t_now < 8.0)
        // {
        //     pwm_val_ = 3000; // 150
        // }
        // else if(t_now < 10.0)
        // {
        //     pwm_val_ = 2048;
        // }
        // else if(t_now < 12.0)
        // {
        //     pwm_val_ = 400;
        // }
        // else if(t_now < 14.0)
        // {
        //     pwm_val_ = 350;
        // }
        // else if(t_now < 16.0)
        // {
        //     pwm_val_ = 300;
        // }
        // else if(t_now < 18.0)
        // {
        //     pwm_val_ = 275;
        // }
        // else if(t_now < 40.0)
        // {
        //     pwm_val_ = 275;
        // }
        // else
        // {
        //     // std::cout << "t_duration: " << t_duration << std::endl;
        //     if(t_duration > 1.0)
        //     {
        //         pwm_update_flag = true;
        //         t_duration = 0.0;
        //     }
        //     else
        //         t_duration += DT;
                
        //     if(pwm_update_flag == true)
        //     {
        //         pwm_update_flag =false;
        //         pwm_val_up += 100;
        //     }

        //     if(pwm_val_up > 4000)
        //         pwm_end_flag = true;
        // }

        if(pwm_end_flag == true)
        {
            pwm_val_down = 2030;
            pwm_val_up = 2030;
        }
            // pwm_val_ = 2048; // end


        std_msgs::UInt16MultiArray pwm16_multiarray_;
        geometry_msgs::PointStamped pwm_stamped_;

        pwm16_multiarray_.data.resize(8);
        // pwm16_multiarray_.data[0] = (uint16_t) pwm_val_;
        // pwm16_multiarray_.data[1] = (uint16_t) pwm_val_;
        // for(int i=2;i<8;i++)+
        // {
        //     pwm16_multiarray_.data[i] = (uint16_t) pwm_val_;
        //     // pwm16_multiarray_.data[i] = (uint16_t) 0;
        // }
        // pwm16_multiarray_.data[2] = (uint16_t) pwm_val_;
        // pwm16_multiarray_.data[3] = (uint16_t) pwm_val_;
        // pwm16_multiarray_.data[4] = (uint16_t) pwm_val_;

        // pwm16_multiarray_.data[0] = (uint16_t) pwm_val_;
        // pwm16_multiarray_.data[2] = (uint16_t) pwm_val_;
        // pwm16_multiarray_.data[4] = (uint16_t) pwm_val_;
        // pwm16_multiarray_.data[6] = (uint16_t) pwm_val_;

        // pwm16_multiarray_.data[0] = (uint16_t) pwm_val_up;
        // pwm16_multiarray_.data[2] = (uint16_t) pwm_val_up;
        // pwm16_multiarray_.data[4] = (uint16_t) pwm_val_up;
        // pwm16_multiarray_.data[6] = (uint16_t) pwm_val_up;

        // pwm16_multiarray_.data[1] = (uint16_t) pwm_val_down;
        // pwm16_multiarray_.data[3] = (uint16_t) pwm_val_down;
        // pwm16_multiarray_.data[5] = (uint16_t) pwm_val_down;
        // pwm16_multiarray_.data[7] = (uint16_t) pwm_val_down;

        pwm16_multiarray_.data[1] = (uint16_t) pwm_val_up;
        pwm16_multiarray_.data[3] = (uint16_t) pwm_val_up;
        pwm16_multiarray_.data[2] = (uint16_t) pwm_val_up;
        pwm16_multiarray_.data[0] = (uint16_t) pwm_val_up;

        pwm16_multiarray_.data[4] = (uint16_t) 0.0;
        pwm16_multiarray_.data[5] = (uint16_t) 0.0;
        pwm16_multiarray_.data[6] = (uint16_t) 0.0;
        pwm16_multiarray_.data[7] = (uint16_t) 0.0;

        // 새로운 값으로 덮기
        // pwm16_multiarray_.data[0] = (uint16_t) 0;
        // pwm16_multiarray_.data[1] = (uint16_t) 500;
        // pwm16_multiarray_.data[2] = (uint16_t) 1000;
        // pwm16_multiarray_.data[3] = (uint16_t) 1500;
        // pwm16_multiarray_.data[4] = (uint16_t) 2000;
        // pwm16_multiarray_.data[5] = (uint16_t) 2500;
        // pwm16_multiarray_.data[6] = (uint16_t) 3000;
        // pwm16_multiarray_.data[7] = (uint16_t) 3500;

        pwm_stamped_.header.stamp = ros::Time::now();
        pwm_stamped_.point.x = pwm_val_up;

        pwm16_pub.publish(pwm16_multiarray_);
        pwm_pub.publish(pwm_stamped_);

        t_now += DT;
        // std::cout << "t_now: " << t_now << std::endl;
        std::cout << "pwm_val_: " << pwm_val_up << std::endl;
        r.sleep();
    }   
}
