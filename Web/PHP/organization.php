<?php

	if (isset($_GET['lang'])) {
		$lang = $_GET['lang'];
	}
	else {
		$lang = 'en';
	}


	switch ($lang) {
		case 'en':
			$lang_file = 'lang_en.php';
			break;

		case 'sk':
			$lang_file = 'lang_sk.php';
			break;
		
		default:
			$lang_file = 'lang_en.php';
			break;
	}

	include_once'languages/'.$lang_file;

?>
