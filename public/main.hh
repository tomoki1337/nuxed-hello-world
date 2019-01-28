<?hh // strict

use namespace Nuxed\Kernel;

require __DIR__.'/../vendor/hh_autoload.hh';

<<__EntryPoint>>
async function main(): Awaitable<noreturn> {
  /**
   * Create the container and kernel instances.
   *
   * you can use the container instance to register
   * services.
   */
  list($container, $kernel) = Kernel\Kernel::create();
  
  
  /**
   * add routes
   */
  $kernel->get('/', HomeHandler::class, 'home');
  $kernel->get(
    '/json',
    (Request $request): Response ==>
      new Message\Response\JsonResponse(dict[
        'message' => 'Hello, World'
      ])
  );

  /**
   * run the kernel application.
   */
  return await $kernel->run();
}
