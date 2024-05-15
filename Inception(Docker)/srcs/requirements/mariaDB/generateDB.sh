#! /bin/sh
service mariadb start

mysql -e "CREATE USER '$ADMIN_USER'@'%' IDENTIFIED BY '$ADMIN_PASSWORD';"
mysql -e "CREATE DATABASE IF NOT EXISTS $DB_NAME;"
mysql -e "CREATE USER '$NEW_USER'@'%' IDENTIFIED BY '$NEW_PASSWORD';"
mysql -e "GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$ADMIN_USER'@'%';"
mysql -e "FLUSH PRIVILEGES;"

service mariadb stop

exec mysqld