#
# Cookbook Name:: openmpi
# Recipe:: default
#
# Copyright 2014, YOUR_COMPANY_NAME
#
# All rights reserved - Do Not Redistribute
#
if platform?("ubuntu")
	package "openmpi-bin" do
		action :install
		options "--force-yes"
	end
	package "openmpi-common" do
		action :install
		options "--force-yes"
	end
	package "libopenmpi1.3" do
		action :install
		options "--force-yes"
	end
	package "libopenmpi-dev" do
		action :install
		options "--force-yes"
	end
else
	# code for redhat-based systems
	package "openmpi" do
		action :install
		options "-y"
	end
	package "openmpi-devel" do
		action :install
		options "-y"
	end
end
