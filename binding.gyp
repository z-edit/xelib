{
  "targets": [
    {
      "target_name": "xelib",
      "sources": [ "src/xelib.cc", "src/lib.cc", "src/meta.cc" ],
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ],
}