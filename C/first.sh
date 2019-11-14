#!/bin/bash

note = "$(date): $*"

echo $note >>~/note.txt
echo Note saved: $note

exit 0
