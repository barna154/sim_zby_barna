# `sim_zby_barna` package
ROS 2 C++ package.  [![Static Badge](https://img.shields.io/badge/ROS_2-Humble-34aec5)](https://docs.ros.org/en/humble/)
## Packages and build

It is assumed that the workspace is `~/ros2_ws/`.

### Clone the packages
``` r
cd ~/ros2_ws/src
```
``` r
git clone https://github.com/barna154/sim_zby_barna
```

### Build ROS 2 packages
``` r
cd ~/ros2_ws
```
``` r
colcon build --packages-select sim_zby_barna --symlink-install
```

<details>
<summary> Don't forget to source before ROS commands.</summary>

``` bash
source ~/ros2_ws/install/setup.bash
```
</details>

``` r
ros2 launch sim_zby_barna launch_example1.launch.py
```

# Delete this part if you are using it as a template

ROS 2 pacage template, to get started, use template by clicking on the Green button labeled [`Use this template`](https://github.com/barna154/sim_zby_barna/generate) / [`Create new repository`](https://github.com/barna154/sim_zby_barna/generate). 

<p align="center"><img src="img/use_this_template01.png" width="60%" /></p>


Let's assume 
- your Github username is `mycoolusername`
- your ROS 2 repo shold be `cool_ros2_package`

Replace everything in the cloned repo:

- `sim_zby_barna` >> `cool_ros2_package` (the folder was already renamed after `Use this template`)
- `barna154` >> `mycoolusername`
- find all `todo` strings and fill the blanks

The easiest way is VS code:

<p align="center"><img src="img/replace01.png" width="60%" /></p>

Now `colcon build` your ROS 2 package and you can start wokring.