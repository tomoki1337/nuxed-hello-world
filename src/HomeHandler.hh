<?hh // strict

use namespace Nuxed\Kernel\Handler;
use type Nuxed\Contract\Http\Message\ResponseInterface;
use type Nuxed\Contract\Http\Message\ServerRequestInterface;

class HomeHandler extends Handler\AbstractHandler {
  use Handler\ResponseFactoryTrait;

  /**
   * Handle the request and return a response.
   */
  public async function handle(
    ServerRequestInterface $request,
  ): Awaitable<ResponseInterface> {
    return $this->html(
        <html>
          <head>
            <meta charset="utf-8" />
            <title>Nuxed</title>
          <link href="https://fonts.googleapis.com/css?family=Nunito:200,600" rel="stylesheet" type="text/css" />
          <style>{$this->getCss()}</style>
          </head>
          <body>
            <div class="flex-center position-ref full-height">
              <div class="content">
                <div class="title">Nuxed Framework</div>
                <img src="https://avatars3.githubusercontent.com/u/45311177?s=400" title="logo"/>
                <div class="links">
                    <a href="https://github.com/nuxed/docs">Docs</a>
                    <a href="https://github.com/nuxed">GitHub</a>
                    <a href="https://fb.me/NuxedFramework">Facebook</a>
                    <a href="mailto:nuxed@protonmail.com">Email</a>
                </div>
              </div>
            </div>
          </body>
        </html>
    );
  }

  protected function getCss(): string {
    return <<<CSS
html, body {
  background-color: #fff;
  color: #636b6f;
  font-family: 'Nunito', sans-serif;
  font-weight: 200;
  height: 100vh;
  margin: 0;
}
.full-height {
    height: 100vh;
}
.flex-center {
    align-items: center;
    display: flex;
    justify-content: center;
}
.position-ref {
    position: relative;
}
.content {
    text-align: center;
}
.title {
    font-size: 84px;
}
.s-title {
    font-size: 68px;
}
.links > a {
    color: #636b6f;
    padding: 0 25px;
    font-size: 13px;
    font-weight: 600;
    letter-spacing: .1rem;
    text-decoration: none;
    text-transform: uppercase;
}
.m-b-md {
    margin-bottom: 50px;
}
CSS;
  }
}
