
class GreetingsController extends Controller {

  public function index(): void{
    $template = $this->loadView('hello.html'); 
		$template->render();
  }

  public function api(): void {
    $greeting = vec["hello world"];
    echo json_encode($greeting);
  }

}