FROM debian:buster
RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install nginx -y
RUN apt-get install wget -y 
RUN apt-get install -y procps
RUN apt-get install mariadb-server -y
RUN apt-get install openssl
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt -subj "/C=MA/ST=Khouribga/L=Khouribga/O=Organisation_NAME/CN=SERVER_NAME"
RUN apt-get install php-mbstring php-zip php-gd php-xml php-pear php-gettext php-cli php-cgi -y
RUN apt-get install php-mysql -y
RUN apt-get install php7.3-fpm -y
RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.4/phpMyAdmin-4.9.4-english.tar.gz
RUN tar -xf phpMyAdmin-4.9.4-english.tar.gz
RUN mv phpMyAdmin-4.9.4-english /var/www/html/phpmyadmin/
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xf latest.tar.gz
RUN mv wordpress/ /var/www/html/wordpress/
COPY srcs tmp/
COPY srcs/default /etc/nginx/sites-available/default
COPY srcs/config.inc.php /var/www/html/phpmyadmin/
COPY srcs/wp-config.php /var/www/html/wordpress/
RUN sh /tmp/setup.sh
RUN chown -R www-data:www-data var/www/html
CMD sh tmp/service-start.sh
