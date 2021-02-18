# Gazebo Simulator

Here we explain how to run a [Gazebo](http://gazebosim.org/) simulation on Docker.

A gazebo image can be built with [the following](https://hub.docker.com/_/gazebo) Dockerfile. It is available in ./docker/gazebo/.

```
FROM gazebo:gzserver8
CMD ["gazebo"]
```

Building the Docker image:

```
$ docker build -t gazebo .
```

Now you need to configure your OS for running GUI apps on Docker. Note that the right thing would be to connect to the Gazebo server (gzserver) from a remote client (gzclient). However, we want to reduce network overhead. Therefore, we choose to run Docker apps with [Rocker](https://github.com/osrf/rocker).

Installing Rocker:
```bash
$ pip install rocker
```

Running with NVidia display cards:
```bash
$ rocker --nvidia --x11 --user --home gazebo
```

Running with other/generic cards:
```bash
$ rocker --devices /dev/dri/card0 --x11 --user --home gazebo
```


## Creating a World (Gazebo Model)

You can follow [this](http://gazebosim.org/tutorials?tut=build_world) tutorial.

## Our Models

For specific experiments, we have been using the following world.

- [Indoor Navigation](#)

You can also play with other models from [there](https://github.com/osrf/gazebo_models).

## Robot Runner and Gazebo

...
