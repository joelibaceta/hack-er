FROM hhvm/hhvm-proxygen:latest

RUN rm -rf /var/www
ADD . /var/www

EXPOSE 80