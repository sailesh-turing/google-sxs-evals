#!/bin/bash
last-changed() {
  num_lines=${1:-10}  # Default to 10 if no argument is provided
  find . -type f -printf '%T@\t%p\n' | sort -n | tail -n "$num_lines"
}