#! /bin/bash

service mysql start
mysql < /var/www/html/phpmyadmin/sql/create_tables.sql
mysql -u root -e "CREATE USER 'yasser'@'localhost' IDENTIFIED BY 'yasser';"
mysql -u root -e "GRANT ALL PRIVILEGES ON *.* TO 'yasser'@'localhost';"
mysql -u root -e "CREATE USER 'issam'@'localhost' IDENTIFIED BY 'issam';"
mysql -u root -e "GRANT SELECT,DELETE,INSERT,UPDATE  ON phpmyadmin.* TO 'issam'@'localhost';"
mysql -u root -e "CREATE DATABASE wordpress DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;"
mysql -u root -e "GRANT ALL PRIVILEGES ON wordpress.* TO 'yasser'@'localhost' IDENTIFIED BY 'yasser';"
