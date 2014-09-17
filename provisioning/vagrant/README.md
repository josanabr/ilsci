# Vagrant

**Vagrant** is a tool used to create rapidly virtual machines for some virtualization tools such as VirtualBox and VMware. In addition, Vagrant is also able to create virtual machine  (VM) instances which run in EC2.

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
A box is a fundamental piece of the Vagrant tool because it defines the parameters of a VM.

A box file, which is actually a tar file, contains three files

- A [virtual] hard disk where the actual operating system resides.
- An ovf file where a set of basic specifications of a VM is defined.
- A Vagrantfile.

You can find boxes from web sites such as:

- [https://vagrantcloud.com/](https://vagrantcloud.com/)
- [https://cloud-images.ubuntu.com/vagrant/](https://cloud-images.ubuntu.com/vagrant/)

If you run this command

```
vagrant box list
```


It is possible that **none** box is listed.
If your environment has not any box then you **can not** create any VM yet.
Lets add some box files to your environment.

### Adding a box

There are at least two basic ways to add a box 

- Using a URL which points to a box 
- Passing as argument to the `box` command a &lt;username&gt;/&lt;box name&gt;

#### Using a URL

The Vagrant sub-command used to create a box given a URL is

```
vagrant box add trusy64 https://cloud-images.ubuntu.com/vagrant/trusty/current/trusty-server-cloudimg-amd64-vagrant-disk1.box
```

This command downloads a copy of the box file and assigns the `trusty64` name to that box.

#### Username/box name

There is a public catalog of [https://vagrantcloud.com/](boxes) which can be used with the vagrant box sub-command.
When you identify a user (e.g. hashicorp) and a particular box name (e.g. precise64) you can run the Vagrant box subcommand as follows

```
vagrant box add hashicorp/precise64
```

## Init

Once you have defined a new box (e.g. trusty64) you are ready to create your first VM using Vagrant. 
Vagrant needs a text file, named Vagrantfile, which contains the description of the VM to be created. 
You can create this file by hand or you can use the `init` sub-command.
Assuming that you have defined a `trusty64` box, you can now create a Vagrantfile as follows

```
vagrant init trusty64
```

Open the Vagrantfile and identify the line where trusty64 appears.

## Starting UP your first VM

Now, you are ready to create and boot up your first machine.
In the same directory where you created the Vagrantfile, run the following command

```
vagrant up
```

Open the VirtualBox control panel and watch how a new VM is created and executed.

## Visiting your VM

When the *vagrant up* command ends, you can log in to the VM as follows

```
vagrant ssh
```

Now, you are in to the VM.
