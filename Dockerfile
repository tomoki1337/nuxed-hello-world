FROM ubuntu:16.04

ARG HHVM_PACKAGE
ARG HHVM_REPO_DISTRO=xenial
ENV HHVM_DISABLE_NUMA true

RUN \
  apt-get update -y && apt-get install -y software-properties-common apt-transport-https \
  && apt-key adv --recv-keys --keyserver hkp://keyserver.ubuntu.com:80 0xB4112585D386EB94 \
  && add-apt-repository "deb https://s3-us-west-2.amazonaws.com/hhvm-downloads/ubuntu ${HHVM_REPO_DISTRO} main" \
  && apt-get update -y \
  && apt-get install -y ${HHVM_PACKAGE} git wget curl \
  && apt-get clean \
  && rm -rf /var/lib/apt/lists/* \
  && sed -i 's,s3-us-west-2.amazonaws.com/hhvm-downloads/,dl.hhvm.com/,' /etc/apt/sources.list \
  && cd /var/www/ \
  && git clone https://github.com/azjezz/nuxed-hello-world \
  && cd nuxed-hello-world \
  && wget https://github.com/composer/composer/releases/download/1.8.0/composer.phar \
  && hhvm composer.phar install \
  && cd public \
  && hhvm -m daemon -c ../server.ini  
