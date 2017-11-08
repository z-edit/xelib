{
  "targets": [
    {
      "target_name": "xelib",
      "sources": [ "src/xelib.cc" ],
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ],
}