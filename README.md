# ROS Configuration

This repository shares preset configurations for ROS to be used in our experiments on robotics software. If you have doubts about ROS1 and ROS2, check [this](https://roboticsbackend.com/ros1-vs-ros2-practical-overview/).

# ROS Foxy and Raspberry
https://emanual.robotis.com/docs/en/platform/turtlebot3/sbc_setup/


Bellow you see a list of related experiments:

| **Experiment**  | **Repository**   |
|---|---|
| *SLAM and Path Coverage (Etienne and Joe)*  | [slam_path](https://github.com/S2-group/slam-path-coverage-missions) |
| *SLAM Performance (Engel)*  | [slam_performance](https://github.com/IntelAgir-Research-Group/thesis-replication-package) |
| *ROS Offloading (Milica)* |
|   -> Sherlock Robot | [sherlock](https://github.com/IntelAgir-Research-Group/sherlock) |
|   -> Robot Bringup | [sherlock_bringup](https://github.com/IntelAgir-Research-Group/sherlock_bringup) |
|   -> Navigation | [navigation](https://github.com/IntelAgir-Research-Group/sherlock_navigation) |
|   -> Localization | [localization](https://github.com/IntelAgir-Research-Group/sherlock_localisation) |
|   -> SLAM | [slam](https://github.com/IntelAgir-Research-Group/sherlock_slam) |
|   -> Camera Node | [raspicam](https://github.com/IntelAgir-Research-Group/raspicam_node) |
|   -> Object Recognition | [object_recognition](https://github.com/IntelAgir-Research-Group/sherlock_obj_recognition) |
|   -> ROS Profiling Messages | [ros_messages](https://github.com/IntelAgir-Research-Group/ros_profilers_msgs) |
|   -> ROS Profilers | [ros_profilers](https://github.com/IntelAgir-Research-Group/ros_melodic_profilers) |
|   -> Robot Runner | [robot_runner](https://github.com/IntelAgir-Research-Group/robot-runner) |
|   -> Analysis | [result_analysis](https://github.com/IntelAgir-Research-Group/offloading_experiment_results) |
| *SLAM Simulation (Kwame)* | [slam_simulation](https://github.com/S2-group/replication_package-SLAM_simulation) |
| *Rosbag Extraction (Berry)* | [rosbag_extraction](https://github.com/BerryC-VU/rosbag_project) |
| *Arduino Power Meter* | [power-meter](https://github.com/S2-group/ros-configurations/tree/main/meter-arduino) |

## [Docker](./docker/)

There we make public some Dockerfiles for running ROS (1 and 2) on your computer so you can "talk" to the robotics system.

## [RaspberryPi](./raspberrypi)

It contains an Unbuntu Bionic (18.4) image that can be used to run ROS(1 and 2) on both, Raspberry Pi 3 and 4. The main ideia is to use it as TurtleBot3's main computer (Raspverry Pi 3B+ is the current official of TurtleBot3 Burger and Waffle Pi).

## [Simulation/Experiment Tools](./gazebo-sim/)

There you will find instructions of how to run simulations on Gazebo, ROS/ROS2, and Robot Runner.
