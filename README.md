# Nuxed Hello, World App

status: not working, image building stuck at composer install 


```console
$ git clone https://github.com/azjezz/nuxed-hello-world
$ cd nuxed-hello-world
$ hhvm $(which composer) install
$ cd public
$ hhvm -m daemon -c ../server.ini
$ # visit https://localhost:8080
```
## Docker
### build the image
```console
docker build -t nuxed-hello-world:latest .
```
### running it
```console
docker-compose up -d
```
by default it requires traefik, comment out that part and uncomment ports if you don't wanna use it, but it's highly recommended 
