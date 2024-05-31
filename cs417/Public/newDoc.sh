#! /bin/bash

newDoc="$1"

cp -r tempDir "$newDoc"
mv "$newDoc/tempDir.md" "$newDoc/$newDoc.md"