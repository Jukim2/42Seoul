#! /bin/bash

curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar 
chmod +x wp-cli.phar
sudo mv wp-cli.phar /usr/local/bin/wp
wp core download --allow-root
wp config create --dbname=$DB_NAME --dbuser=$NEW_USER --dbpass=$NEW_USER_PASSWORD --dbhost=mariadb --allow-root
wp core install --url=jukim2.42.fr --title=$TITLE --admin_user=$ADMIN_USER --admin_password=$ADMIN_PASSWORD --admin_email=$ADMIN_EMAIL --allow-root
wp user create $NEW_USER $NEW_USER_EMAIL --user_pass=$NEW_USER_PASSWORD --allow-root

php-fpm7.4 -F