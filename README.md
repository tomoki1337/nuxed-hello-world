# Nuxed Hello, World App

---

```console
$ git clone https://github.com/azjezz/nuxed-hello-world
$ cd nuxed-hello-world
$ hhvm $(which composer) install
$ cd public
$ hhvm -m daemon -c ../server.ini
$ # visit https://localhost:8080
```
##Docker
### build the image
```console
docker build -t nuxed/hello-world:latest .
```
### running it
```console
docker-compose up -d
```console
