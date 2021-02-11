
# Dockerfiles

Here, you'll find Dockerfiles for building ROS1 and ROS2 images. They are explicitly set up to build a *ROS1 Melodic or ROS2 Foxy* image as these were used during development. However, these versions can easily be changed by editing the dockerfile and stating any other version to be required. This would involve changing only a minor subset of one line for each of the dockerfiles. 

Specifically, you can change *FROM ros:foxy* to *FROM ros:eloquent* or any other alteration involving a **correct** ROS version. 

**NOTE**: that the respective ROS1 and ROS2 Dockerfiles are created with a purpose, as their correct setup for robot-runner to be able to run, involve different steps. Therefore only alter the ROS1 dockerfile to any other ROS1 version, and do the same for the ROS2 dockerfile.

# Build ROS Docker Images

**NOTE** that Docker must be already installed. If you do not know how, please check [this](https://docs.docker.com/engine/install/ubuntu/).

```bash
$ git clone git@github.com:S2-group/ros-configurations.git
$ cd ros-configuration/docker/ros2
$ docker build -f- . < Dockerfile
```
If you want to use ROS1, please use the path *ros-configuration/docker/ros1* instead.

You can check your Docker images:

```bash
$ docker images | grep ros
```

You should get something like the following (with seconds/minutes ago, of course):

```
ros                 eloquent            06184ad8a88a        2 weeks ago         829MB
```

# Run Docker Images

After the following command, you will get the bash shell in the container.

```bash
$ docker exec -it <container name> /bin/bash
```

Now it is play time! Please, check how to proceed with [Robot Runner](https://github.com/S2-group/robot-runner).

# TODO

@Michel: I need to check how to set RR local path so it's copied when building the Docker image.
