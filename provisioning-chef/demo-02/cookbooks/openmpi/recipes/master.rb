if platform?("ubuntu")
	package "build-essential" do
		action :install
		options "--force-yes"
	end
else 
	package "make" do
		action :install
		options "-y"
	end
	package "gcc" do
		action :install
		options "-y"
	end
	package "gcc-c++" do
		action :install
		options "-y"
	end
	package "kernel-devel" do
		action :install
		options "-y"
	end
end
cookbook_file "/home/#{node[:users][:username]}/openmpi_demo.c" do
	source "openmpi_demo.c"
	mode "0644"
	owner "#{node[:users][:username]}"
end
cookbook_file "/home/#{node[:users][:username]}/nbodypipe.c" do
	source "nbodypipe.c"
	mode "0644"
	owner "#{node[:users][:username]}"
end
cookbook_file "/home/#{node[:users][:username]}/machinefile" do
	source "machinefile"
	mode "0644"
	owner "#{node[:users][:username]}"
end
cookbook_file "/home/#{node[:users][:username]}/README" do
	source "README"
	mode "0644"
	owner "#{node[:users][:username]}"
end
template "/home/#{node[:users][:username]}/Makefile" do
	source "Makefile.erb"
	mode "0644"
	owner "#{node[:users][:username]}"
	variables(
		:shareddir => "#{node[:nfs][:shareddirectory]}"
	)
end
template "/home/#{node[:users][:username]}/Makefile.nbody" do
	source "Makefile.nbody.erb"
	mode "0644"
	owner "#{node[:users][:username]}"
	variables(
		:shareddir => "#{node[:nfs][:shareddirectory]}"
	)
end
template "/home/#{node[:users][:username]}/runnbody.sh" do
	source "runnbody.sh.erb"
	mode "0744"
	owner "#{node[:users][:username]}"
	variables(
		:shareddir => "#{node[:nfs][:shareddirectory]}"
	)
end
