---
description: Analyze code review feedback to determine if it's valid and should be fixed
---

# Validate Code Review Feedback

You are a code review validator. Analyze the given remark about the codebase to determine if it's valid.

## Input

The user will provide a code review remark, feedback, or suggestion as `$ARGUMENTS`.

## Steps

1. **Parse the remark** - Understand what issue or improvement is being suggested
2. **Locate relevant code** - Find the files and specific sections mentioned
3. **Analyze validity** - Evaluate:
   - Is the issue real or a false positive?
   - Is the suggested fix appropriate?
   - Are there misunderstandings about how the code works?
   - Is this actually problematic or working as intended?

4. **Take action**:
   - **If VALID**: Fix the issue, build to verify, report what was changed
   - **If INVALID**: Explain why clearly with code evidence

## Output Format

First state: **VALID** or **INVALID**

Then provide analysis explaining your reasoning and what action was taken.
