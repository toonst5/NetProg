<?php

// Map CSV file to array
$rows = array_map('str_getcsv', file('/home/sam/Documents/Server/chat.csv'));
$header = array_shift($rows);
$data = array();
foreach ($rows as $row)
{
        $data[] = array_combine($header, $row);
}

// Process Data if need be
foreach($data AS $key => $val)
{
        // Processing here
}

 //Creates XML string and XML document using the DOM
$xml = new DomDocument('1.0', 'UTF-8');


// Map CSV file to array
$rows = array_map('str_getcsv', file('/home/sam/Documents/Server/chat.csv'));
$header = array_shift($rows);
$data = array();
foreach ($rows as $row)
{
        $data[] = array_combine($header, $row);
}

// Process Data if need be
foreach($data AS $key => $val)
{
        // Processing here
}

 //Creates XML string and XML document using the DOM
 
$xml = new DomDocument('1.0', 'UTF-8');

//Add root node
$root = $xml->createElement('root');
$xml->appendChild($root);

// Add child nodes
foreach($data AS $key => $val)
{
        $entry = $xml->createElement('entry');
        $root->appendChild($entry);

        foreach($val AS $field_name => $field_value)
        {
                $field_name = preg_replace("/[^A-Za-z0-9]/", '', $field_name); >
                $name = $entry->appendChild($xml->createElement($field_name));
                $name->appendChild($xml->createCDATASection($field_value));
        }

}


// Set the formatOutput attribute of xml to true
$xml->formatOutput = true;


header('Content-Type: text/xml');
echo $xml->saveXML();

// Save as file
$xml->save('xml-import.xml'); // save as file

?>

