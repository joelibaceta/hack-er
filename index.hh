
<<__EntryPoint>>
async function main(): Awaitable<void> {

  require_once(__DIR__.'/vendor/autoload.hack');
  require_once(__DIR__.'/lib/view.hh');
  require_once(__DIR__.'/lib/controller.hh');
  require_once(__DIR__.'/lib/router.hh');

  $path = basename($_SERVER['REQUEST_METHOD']);

  $router = new Router($_SERVER);
  $router->apply(); 

}
