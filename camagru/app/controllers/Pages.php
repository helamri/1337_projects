<?php
    class Pages extends Controller {
        public function __construct(){
                $this->pageModel = $this->model('page');
        }
        public function index(){
            $pagi = 0;
        if(isset($_POST["page"]))
        {
            $pagi= $_POST["page"];

            $pagi= ($pagi*5)-5;
        }
        $pages = $this->pageModel->showall($pagi);
        $datashow = [
            'pages' => $pages
        ];
        $this->view('/pages/index', $datashow);
        }
        public function about(){
            $data = [
                'title' => 'a small web application allowing to
                make basic photo and video editing using the webcam and some predefined images.'
            ];
            $this->view('pages/about', $data);
        }
    }