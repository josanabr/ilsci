Description
===========

This directory presents two examples about how to do provisioning of virtual environments using Vagrant and Chef. 

Directory `demo-01` shows how to provision one single virtual machine with Apache and PHP. To run the code inside, execute `vagrant up`.

Directory `demo-02` shows how to create a computational cluster where the following software tools are installed:

- **OpenMPI**: This is a C/C++ library used to develop SIMD programs for non-shared memory systems.

- **Ganglia**: It is a monitoring tool and it can be used to watch the activity happening with the node in the cluster.

To run the code inside, execute `vagrant up`. **NOTE** before to run recipes given in `demo-02` be sure that virtual machine created in `demo-01` is not running.

