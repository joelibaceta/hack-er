

class Router {

  private string $action="index";
  private string $controller;
  private string $method;
  private string $query_string;
  
  private Map<string, string> $routes = Map {};

  public function __construct($server) {
 
    $this->query_string = $server["QUERY_STRING"]; 

    $request_url = (isset($server['REQUEST_URI'])) ? $server['REQUEST_URI'] : '';
    $script_url  = (isset($server['PHP_SELF'])) ? $server['PHP_SELF'] : '';

    $url = str_replace('index.hh/', '', $script_url);

    $segments = explode('/', $url);


    if(isset($segments[1]) && $segments[1] != '') $this->controller = $segments[1];
    if(isset($segments[2]) && $segments[2] != '') $this->action = $segments[2];

  }

  public function route(string $key, string $path): void {
    $this->routes->add(Pair {$key, $path});
  }

  public function apply(): void{

    $path = __DIR__ . '/../src/controllers/' . $this->controller . '.hh';


    $controller_name = mb_convert_case($this->controller, MB_CASE_TITLE, "UTF-8") . "Controller";
    $action_name = $this->action;

    if (file_exists($path)) {
      require_once($path); 
        if(!method_exists($controller_name, $this->action)){
          echo "Method not found";
        } else {
          $obj = new $controller_name();
          $obj->$action_name();
        }
    } else {
      echo $path;
       echo "Invalid route";
    }


 
  }

}
 