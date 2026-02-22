# Validate Code Review Feedback

Analyzes code review feedback/remarks to determine if they are valid and should be fixed.

## Usage

```
/validate <remark or feedback text>
```

## Arguments

- `$ARGUMENTS` - The code review remark, feedback, or suggestion to validate

## Instructions

You are a code review validator. Your task is to analyze the given remark about the codebase and determine if it is valid.

### Steps

1. **Understand the remark**: Parse the feedback to understand what issue or improvement is being suggested.

2. **Locate the relevant code**: Find the files and specific code sections mentioned in the remark.

3. **Analyze validity**: Evaluate whether the remark is valid by considering:
   - Is the issue real or a false positive?
   - Is the suggested fix appropriate?
   - Are there any misunderstandings about how the code works?
   - Is the code actually problematic or does it work as intended?
   - Is this a style preference vs. an actual bug/improvement?

4. **Take action**:
   - **If VALID**: Fix the issue directly in the code, build to verify, then report what was changed.
   - **If INVALID**: Explain clearly why the remark is not valid, citing specific code behavior or design decisions.

### Output Format

First state your conclusion: **VALID** or **INVALID**

Then provide your analysis:
- For valid remarks: explain the issue and what you fixed
- For invalid remarks: explain why the remark is incorrect or not applicable

## Example

Input: `/validate src/core/app.cpp:86-87: Генерация instance ID через QRandomGenerator — потенциальная коллизия. Рекомендация: Использовать QUuid::createUuid()`

Analysis process:
1. Found m_instanceId in app.h and app.cpp
2. Discovered m_instanceId is never actually used anywhere
3. Single-instance is handled by QLockFile, not by this ID
4. Conclusion: The remark identifies dead code, but the fix is deletion, not UUID

Output:
```
**INVALID** (but partially correct)

The remark correctly identifies that QRandomGenerator is not ideal for unique IDs.
However, the real issue is that m_instanceId is DEAD CODE - it's initialized but never used.
Single-instance functionality is handled by QLockFile which doesn't need this ID.

Fix applied: Removed the unused m_instanceId member entirely.
```
