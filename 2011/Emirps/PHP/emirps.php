<?php


$input = 100;
$counter = 0;

//Main
for($i = 2; $i <= $input; $i++){
	if (is_prime($i)){

		if(is_emirp($i)) $counter += $i;
	}
}

	echo $counter;


//FUNCIONES ADICIONALES

//Calculamos si un número es primo
function is_prime ($n){
	
	for($i = 2; $i*$i <= $n; $i++){
		if($n % $i == 0) return false;
	}

	return true;
}

//Calcula si el número es emirp
function is_emirp($i){

	$seq_char = (string) $i;
	$counter_reverted = strlen($seq_char)-1;
	$emirp = 0;
	$emirp = (int) strrev($seq_char);

	for($i = 0; $i <= strlen($seq_char)/2; $i++){
		if ($seq_char[$i] == $seq_char[$counter_reverted]) return false;
		$counter_reverted--;

	}

	return is_prime($emirp);
	
}













?>
