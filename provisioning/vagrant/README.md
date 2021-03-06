# A gentle intro to Vagrant

**Author** John A Sanabria

**E-mail** john.sanabria@correounivalle.edu.co

## Preliminaries

To take full advantage of this document is highly recommended to get access a computer with Vagrant installed.
In order to do this it is necessary install:

- VirtualBox 
  - [4.2.x 64 bits](http://172.17.9.50/boxes/VirtualBox-4.2.24-92790-Linux_amd64.run)
  - [4.2.x 32 bits](http://172.17.9.50/boxes/VirtualBox-4.2.24-92790-Linux_x86.run)

- Vagrant 
  - [1.6.x 64 bits](http://172.17.9.50/boxes/vagrant_1.6.5_x86_64.deb)
  - [1.6.x 32 bits](http://172.17.9.50/boxes/vagrant_1.6.5_i686.deb)

### Installing VirtualBox

Assuming you are installing VirtualBox in an Ubuntu 64 bits system:

1. Change permissions to the `.run` file e.g. `chmod +x VirtualBox-4.2.24-92790-Linux_amd64.run`
2. Run the following command `sudo ./VirtualBox-4.2.24-92790-Linux_amd64.run`

### Installing Vagrant

Assuming you are installing Vagrant in an Ubuntu 64 bits system, run the following command:

```
sudo dpkg -i vagrant_1.6.5_x86_64.deb
```

### Test Vagrant

Verify if you are ready, run

```
vagrant version
```

If you get a message like this

```
Installed Version: 1.6.3
```

You are ready to follow with this reading.

## Introduction

**Vagrant** is a tool used to create rapidly virtual machines(VMs) for some virtualization tools (a.k.a. hypervisors) such as VirtualBox and VMware. 
In addition, Vagrant is also able to create VM instances to run in EC2.

Vagrant is a CLI tool which provides a set of sub-commands which are used to manage and interact with VMs. 
You can find more about these sub-commands running the following command.

```
vagrant help
```

Vagrant provides a wide range of sub-commands but these  `box`, `init`, `up` and `destroy`; are enough for our instructional purposes. 

Now, we will try to answer the following question **How we can create an operational VM in few seconds?**

In order to answer this question is necessary to know about some concepts and sub-commands used by Vagrant. 
As follows, you will learn about `box`, `init` and `up` sub-commands.

## Box

A box is a package format for Vagrant environments. 
A box is a fundamental piece of the Vagrant tool because in it is specified the parameters to rule the definition of a VM.

A box file, which is actually a tar file, contains three files:

- A [virtual] hard disk where the actual operating system resides.
- An ovf file where a set of basic specifications of a VM is defined.
- A Vagrantfile.

**Where those boxes can be found?**
You can find a plethora of boxes from these web sites:

- [https://vagrantcloud.com/](https://vagrantcloud.com/)
- [https://cloud-images.ubuntu.com/vagrant/](https://cloud-images.ubuntu.com/vagrant/)

Now, lets see how many boxes are defined in your environment. 
Then run the following command

```
vagrant box list
```

It is possible that **none** box is listed.
If your environment has not any box then you **can not** create any VM yet.
Lets add some boxes to your environment.

### Adding a box

There are at least two basic ways to add a box 

- Using a URL which points to a box.
- Passing as argument to the `box` command a &lt;username&gt;/&lt;box name&gt;.

#### Using a URL

The Vagrant sub-command used to create a box given a URL is

```
vagrant box add trusty64 https://cloud-images.ubuntu.com/vagrant/trusty/current/trusty-server-cloudimg-amd64-vagrant-disk1.box
```

A copy of that box is locally available 


```
vagrant box add trusty64 http://172.17.9.50/boxes/trusty-server-cloudimg-amd64-vagrant-disk1.box
```

This command downloads a copy of the box file and assigns the `trusty64` name to that box.

#### Username/box name

There is a public catalog of [https://vagrantcloud.com/](boxes) which can be used with the Vagrant `box` sub-command.
When you identify a user (e.g. hashicorp) and a particular box name (e.g. precise64) you can run the Vagrant `box` sub-command as follows

```
vagrant box add hashicorp/precise64
```

## Init

Once you have defined a new box (e.g. trusty64) you are ready to create your first VM using Vagrant. 
Vagrant needs a text file, named `Vagrantfile`, which contains the description of the VM to be created. 
You can create this file with a text editor or you can use the `init` sub-command.
Assuming that you have defined a `trusty64` box, you can now create a Vagrantfile as follows

```
vagrant init trusty64
```

Open the Vagrantfile and identify the line where the word `trusty64` appears.

## Starting UP your first VM

Now, you are ready to create and boot up your first machine.
In the same directory where you created the Vagrantfile, run the following command

```
vagrant up
```

Open the VirtualBox control panel and watch how a new VM is created and run.

## Visiting your VM

When the `vagrant up` command ends, you can log in to the VM as follows

```
vagrant ssh
```

Now, you are in to the VM.

## Destroying your VM

To destroy your VM, log out from the VM and run the following command:

```
vagrant destroy
```

## Next...

Visit this [document](https://docs.google.com/document/d/10cnPyFyFFKF_fpI9fHjwr6HQEk7vCiPMRtofUQcrHAU/edit?usp=sharing) which will teach you how to customize a Vagrantfile in such a way that multiple VMs exhibiting particular and different characteristics can be defined.
