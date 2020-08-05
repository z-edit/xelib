{
  "targets": [
    {
      "target_name": "xelib",
      "sources": [
        "src/cpp/xelib.cc",
        "src/cpp/lib.cc",
        "src/cpp/meta.cc",
        "src/cpp/messages.cc",
        "src/cpp/setup.cc",
        "src/cpp/resources.cc",
        "src/cpp/files.cc",
        "src/cpp/masters.cc",
        "src/cpp/elements.cc",
        "src/cpp/errors.cc",
        "src/cpp/serialization.cc",
        "src/cpp/elementValues.cc",
        "src/cpp/records.cc",
        "src/cpp/filter.cc"
      ],
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ],
}
