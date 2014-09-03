Tutorial of Rapid Provisioning Tools
====================================
Introduction
------------
This repository contains different examples to intend to help you in the process of learning how to use different tools used in provisioning scenarios such as Vagrant, Chef and Ansible.

This repository will be modified in a weekly basis in order to incorporate new examples to help the student to grasp the concepts related with provisioning of high performance computational infrastructures.
Some topics that will be taught during the semester are:
* Using Vagrant for rapid VM creation
* Deploying a Web Server
* Deploying computational clusters
        * OpenMPI
        * HTCondor
        * Hadoop

Installing the Provisioning Tools
---------------------------------
You can run the examples provided in this repository in your own computer or laptop.
The following tools are needed:

* Vagrant
* Ansible

### Installing Vagrant
Vagrant is a program used to create Virtual Machines (VMs) for different hypervisors and cloud providers such as VMWare, VirtualBox and Amazon.
In this course you will use VirtualBox 4.2.x and Vagrant 1.6.x.
Then you need to download VirtualBox (use this [link](https://www.virtualbox.org/wiki/Download_Old_Builds_4_2)) and Vagrant (use this [link](https://www.vagrantup.com/downloads.html)).

Interacting with Vagrant
------------------------
In order to work with Vagrant is necessary to obtain a **box** which will allow you to create VM instances.
A box is defined in the Vagrant site as follows *"Boxes are the package format for Vagrant environments. A box can be used by anyone on any platform that Vagrant supports to bring up an identical working environment."*

In order to associate a box with a name at your computer, run the following command

> vagrant box add trusty64 http://cloud-images.ubuntu.com/vagrant/trusty/current/trusty-server-cloudimg-amd64-vagrant-disk1.box

In this case the box file is accessed from Internet. 
You can also download the box file first then associate the box (now in your filesystem) with a name.
The following commands are similar to the command above

> cd /tmp
>
> wget -t0 -c http://cloud-images.ubuntu.com/vagrant/trusty/current/trusty-server-cloudimg-amd64-vagrant-disk1.box
>
> vagrant box add trusty64 /tmp/trusty-server-cloudimg-amd64-vagrant-disk1.box 

This time you have the box file in your filesystem for future references.

You can find additional Ubuntu boxes in this [link](http://cloud-images.ubuntu.com/vagrant/).

### Creating your first VM with Vagrant

Assuming that you have a box named **trusty64** run the following command

> vagrant init trusty64
>
> vagrant up
>
> vagrant ssh

The **init** Vagrant command creates a file named *Vagrantfile*.
This file is very important because in it can be specified particular characteristics of a VM e.g. number of processors and memory size.

The **up** command actually creates the VM and runs it.

The **ssh** command opens a ssh connection to the recently created VM. 
Onwards you can interact with the VM as any other VM.


