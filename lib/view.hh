class View {
 
	private $template;

	public function __construct(string $template): void {
		$this->template = __DIR__ . '/../src/views/'. $template;
	}

	public function render(): void { 
		$myfile = fopen($this->template, "r");
    echo fread($myfile,filesize($this->template));
	}
    
}