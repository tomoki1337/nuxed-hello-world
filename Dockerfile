FROM hhvm/hhvm

RUN apt-get update -qq && \
        apt-get install -y -qq git curl php-cli php-mbstring git unzip && \
        apt-get -y clean

COPY --from=composer /usr/bin/composer /usr/local/bin/composer
ENTRYPOINT [ "hhvm", "-d", "hhvm.http.slow_query_threshold=30000", "/usr/local/bin/composer" ]
RUN \
  mkdir /var/www \
  && cd /var/www \
  && git clone https://github.com/azjezz/nuxed-hello-world
RUN \
  cd /var/www/nuxed-hello-world \
  && composer install \
  && hhvm vendor/bin/hh-autoload
RUN \
  cd /var/www/nuxed-hello-world/public \
  && hhvm -m daemon -c ../server.ini

