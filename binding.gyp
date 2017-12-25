{
  "targets": [
    {
      "target_name": "xelib",
      "sources": [
        "src/xelib.cc",
        "src/lib.cc",
        "src/meta.cc",
        "src/messages.cc",
        "src/setup.cc",
        "src/archives.cc",
        "src/files.cc",
        "src/masters.cc",
        "src/elements.cc",
        "src/errors.cc",
        "src/serialization.cc",
        "src/elementValues.cc",
        "src/records.cc",
        "src/filter.cc"
      ],
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ],
}