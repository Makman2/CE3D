CE3D
====

Console Engine 3D
-----------------

This is a 3D engine for the console. It is planned to support C++ and C. Maybe
we can write wrappers for other languages.

To get a picture of what is to come, take a look at the roadmap.

This is currently a WIP. For more info about what's in our heads, take a look
at:
https://github.com/Makman2/TE3D (the chaotic old version)

The new implementation aims to be easy to use and platform independent.

If you have any bugs or hints feel free to contact us, you find email adresses
in the AUTHORS file. We especially appreciate hints about our API.

Reliability
-----------
We try to improve and maintain code quality and functionality with
* unit tests/integration tests
* a code checking utility
* a continous build, test and codecheck server (planned)

If you have any hints about how we could improve our code quality in any way,
feel free to contact us.

Roadmap
-------
* Version 0.1
  - C++ only.
  - Drawing a point based model to the console (orthogonal projected).
  - Transforming the model/world, moving the camera.

* Version 0.2
  - API documented and shall not be changed
  - Drawing line-based and triangle-based models
  - Loading .obj files
  - Means to control framerate available

* Version 0.3
  - API freeze
  - Test application available

Participate
-----------
To participate, read this readme and look into the codestyle guidelines (see
[CODESTYLE.md](CODESTYLE.md)). If you have any questions (what can be done, is
this ok, whatever you have in mind), let us know!

We also support limited codestyle checking via coala. You can do that without
having to install coala from the CE3D root directory:

```
git submodule init
git submodule update
submodules/coala/coala
```

This will check all code for some spacing issues and assure maximum line length.

If you want to see all TODOs and FIXMEs in the code, use:

```
submodules/coala/coala todos
```

Pronounciation
--------------
Seed.

Logo
----

    ######################################
    ######################################
    ###############################P*#####
    ###########################P*´   #####
    #######################P*´ _.<#  #####
    ###################P*´ _.<#####  #####
    ###############P*´ _.<#########<######
    ###########P*´ _.<####################
    #######P*´ _.<########################
    #####´ _.<############################
    #####  ######################P*´ #####
    #####  ##################P*´ _.<######
    #####_.##############P*´ _.<##########
    #################P*´ _.<##############
    #############P*´ _.<##################
    #########P*´ _.<#############P*´ #####
    #####P*´ _.<#############P*´ _.<######
    #####_.<#############P*´ _.<##########
    #################P*´ _.<##############
    #############P*´ _.<##################
    #########P*´ _.<###############´ #####
    #####P*´ _.<###################  #####
    #####_.<#######################  #####
    ###########################P*´ _.#####
    #######################P*´ _.<########
    ###################P*´ _.<############
    #####P*########P*´ _.<################
    #####  ####P*´ _.<####################
    #####  P*´ _.<########################
    #####  _.<############################
    #####<################################
    ######################################
    ######################################

The SVG-version can be found at:
[doc/CE3D.svg](doc/CE3D.svg)
