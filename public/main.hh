<?hh // strict

use namespace Nuxed\Kernel;

require __DIR__.'/../vendor/hh_autoload.hh';

<<__EntryPoint>>
async function main(): Awaitable<noreturn> {
  /**
   * Create an Kernel instance.
   */
  $kernel = new Kernel\Kernel(dict[/* default production config */]);

  /**
   * add route
   */
  $kernel->get('/', HomeHandler::class, 'home');

  /**
   * run the kernel application.
   */
  return await $kernel->run();
}
