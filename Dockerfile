FROM hhvm/hhvm

RUN apt-get update -qq && \
        apt-get install -y -qq git curl php-cli php-mbstring git unzip && \
        apt-get -y clean

COPY --from=composer /usr/bin/composer /usr/local/bin/composer

RUN composer

ARG PUID=1000
ARG PGID=1000
RUN groupadd -g ${PGID} docker && \
  useradd -u ${PUID} -g docker -m docker
USER docker

ENTRYPOINT [ "hhvm", "-d", "hhvm.http.slow_query_threshold=30000", "/usr/local/bin/composer" ]
RUN \
  mkdir /home/docker/www \
  && cd /home/docker/www \
  && git clone https://github.com/azjezz/nuxed-hello-world
RUN \
  cd /home/docker/www/nuxed-hello-world \
  && composer install \
  && hhvm vendor/bin/hh-autoload
RUN \
  cd /home/docker/www/nuxed-hello-world/public \
  && hhvm -m daemon -c ../server.ini

