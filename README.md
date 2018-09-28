# proc_actuators

This module is a process that send an action to the actuators based on [ROS](http://www.ros.org/)

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

```bash
$ git clone https://github.com/sonia-auv/proc_actuators
```

### Prerequisites

You must install S.O.N.I.A's ROS repostitories to use this module.

S.O.N.I.A's installation instruction are available at [SONIA's Installation](https://sonia-auv.readthedocs.io/user/installation/)

## General informations

### Input

controller mission service. [service structure](https://github.com/sonia-auv/proc_actuators/blob/develop/srv/cmActionSrv.srv)

### Output

io board ros message

### Algorithms

simply convert controller mission service to a message for the io board

## Running the tests

Not implemented yet

## Deployment

must be deployed with the sonia custom command sas

## Built With

* [ROS](http://www.ros.org/) - ROS Robotic Operating System

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags).

## Authors

* **Olivier Beguin** - *initial work* - [vdot42](https://github.com/Vdot42)
* **Marc-Antoine Couture** - *initial work* - [coumarc9](https://github.com/coumarc9)
* **Lucas Mongrain** - *modification* - [0x72d0](https://github.com/0x72D0)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the GNU GPL V3 License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgement
