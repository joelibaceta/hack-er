class Controller {

  public function loadView(string $name): View {
		$view = new View($name);
		return $view;
	}
    
}

