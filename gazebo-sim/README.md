# Gazebo Simulator

Here we explain how to run a [Gazebo](http://gazebosim.org/) simulation.

## Docker

All the environment is already set by using Docker and [this](https://hub.docker.com/_/gazebo) Dockerfile. 

```
FROM gazebo:gzserver8
CMD ["gazebo"]
```

Build it:

```
$ docker build -t gazebo .
```

Now you need to configure your OS for [running GUI apps on Docker](https://medium.com/@SaravSun/running-gui-applications-inside-docker-containers-83d65c0db110). Note that the right thing to do would be to connect to gxserver by using a remote gxclient. However, we want to reduce overload on the docker container. Therefore, we choose to run Docker apps with [Rocker](https://github.com/osrf/rocker).

Installing Rocker:
```bash
$ pip install rocker
```

For NVidia cards:
```bash
$ rocker --nvidia --x11 --user --home gazebo
```

For other generic cards:
```bash
$ rocker --devices /dev/dri/card0 --x11 --user --home gazebo
```


## Creating a World

You can follow [this](http://gazebosim.org/tutorials?tut=build_world) tutorial.

## Our Models

For specific experiments, we have modeled the following environments in [SDF](http://sdformat.org/) (Simulation Description Format):

- [Indoor Navigation](#)

You can also play with other models in [here](https://github.com/osrf/gazebo_models).

## Robot Runner and Gazebo

...
