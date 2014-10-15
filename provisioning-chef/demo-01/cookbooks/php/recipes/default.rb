execute "update" do
	user "root"
	command "apt-get update"
	action :run
end
package "php5 libapache2-mod-php5" do
	action :install
end
if platform?("ubuntu")
	if node["platform_version"].to_f == 14.04
		cookbook_file "/var/www/html/info.php" do
			source "info.php"
			mode 0644
			owner "root"
		end 
	else
		cookbook_file "/var/www/info.php" do
			source "info.php"
			mode 0644
			owner "root"
		end 
	end
end
