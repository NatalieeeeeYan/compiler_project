; ModuleID = 'llvm-link'
source_filename = "llvm-link"
target datalayout = "e-m:o-i64:64-i128:128-n32:64-S128"
target triple = "arm64-apple-macosx15.0.0"

%struct.timeval = type { i64, i32 }

@TOKEN_NUM = global i32 0
@TOKEN_OTHER = global i32 1
@last_char = global i32 32
@num = global i32 0
@other = global i32 0
@cur_token = global i32 0
@llvm.global_ctors = appending global [2 x { i32, ptr, ptr }] [{ i32, ptr, ptr } { i32 65535, ptr @before_main, ptr null }, { i32, ptr, ptr } { i32 65535, ptr @__GLOBAL_init_65535, ptr null }]
@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str.1 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@.str.2 = private unnamed_addr constant [4 x i8] c"%d:\00", align 1
@.str.3 = private unnamed_addr constant [4 x i8] c" %d\00", align 1
@.str.4 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1
@_sysy_us = global [1024 x i32] zeroinitializer, align 4
@_sysy_s = global [1024 x i32] zeroinitializer, align 4
@_sysy_m = global [1024 x i32] zeroinitializer, align 4
@_sysy_h = global [1024 x i32] zeroinitializer, align 4
@_sysy_idx = global i32 0, align 4
@__stderrp = external global ptr, align 8
@.str.5 = private unnamed_addr constant [35 x i8] c"Timer@%04d-%04d: %dH-%dM-%dS-%dus\0A\00", align 1
@_sysy_l1 = global [1024 x i32] zeroinitializer, align 4
@_sysy_l2 = global [1024 x i32] zeroinitializer, align 4
@.str.6 = private unnamed_addr constant [25 x i8] c"TOTAL: %dH-%dM-%dS-%dus\0A\00", align 1
@_sysy_start = global %struct.timeval zeroinitializer, align 8
@_sysy_end = global %struct.timeval zeroinitializer, align 8
@__dso_handle = external hidden global i8

define i32 @next_char() {
bb1:
  %r100 = call i32 @getch()
  store i32 %r100, ptr @last_char, align 4
  %r101 = load i32, ptr @last_char, align 4
  ret i32 %r101
}

define i32 @is_space(i32 %r102) {
bb2:
  %r103 = alloca i32, align 4
  store i32 %r102, ptr %r103, align 4
  %r104 = load i32, ptr %r103, align 4
  %r105 = icmp eq i32 %r104, 32
  br i1 %r105, label %bb3, label %bb6

bb6:                                              ; preds = %bb2
  %r106 = load i32, ptr %r103, align 4
  %r107 = icmp eq i32 %r106, 10
  br i1 %r107, label %bb3, label %bb4

bb3:                                              ; preds = %bb6, %bb2
  ret i32 1

0:                                                ; No predecessors!
  br label %bb5

bb4:                                              ; preds = %bb6
  ret i32 0

1:                                                ; No predecessors!
  br label %bb5

bb5:                                              ; preds = %1, %0
  ret i32 0
}

define i32 @is_num(i32 %r108) {
bb7:
  %r109 = alloca i32, align 4
  store i32 %r108, ptr %r109, align 4
  %r110 = load i32, ptr %r109, align 4
  %r111 = icmp sge i32 %r110, 48
  br i1 %r111, label %bb11, label %bb9

bb11:                                             ; preds = %bb7
  %r112 = load i32, ptr %r109, align 4
  %r113 = icmp sle i32 %r112, 57
  br i1 %r113, label %bb8, label %bb9

bb8:                                              ; preds = %bb11
  ret i32 1

0:                                                ; No predecessors!
  br label %bb10

bb9:                                              ; preds = %bb11, %bb7
  ret i32 0

1:                                                ; No predecessors!
  br label %bb10

bb10:                                             ; preds = %1, %0
  ret i32 0
}

define i32 @next_token() {
bb12:
  br label %bb13

bb13:                                             ; preds = %bb14, %bb12
  %r114 = load i32, ptr @last_char, align 4
  %r115 = call i32 @is_space(i32 %r114)
  %r116 = icmp ne i32 %r115, 0
  br i1 %r116, label %bb14, label %bb15

bb14:                                             ; preds = %bb13
  call void @next_char()
  br label %bb13

bb15:                                             ; preds = %bb13
  %r117 = load i32, ptr @last_char, align 4
  %r118 = call i32 @is_num(i32 %r117)
  %r119 = icmp ne i32 %r118, 0
  br i1 %r119, label %bb16, label %bb17

bb16:                                             ; preds = %bb15
  %r120 = load i32, ptr @last_char, align 4
  %r121 = sub i32 %r120, 48
  store i32 %r121, ptr @num, align 4
  br label %bb19

bb19:                                             ; preds = %bb20, %bb16
  %r122 = call i32 @next_char()
  %r123 = call i32 @is_num(i32 %r122)
  %r124 = icmp ne i32 %r123, 0
  br i1 %r124, label %bb20, label %bb21

bb20:                                             ; preds = %bb19
  %r125 = load i32, ptr @num, align 4
  %r126 = mul i32 %r125, 10
  %r127 = load i32, ptr @last_char, align 4
  %r128 = add i32 %r126, %r127
  %r129 = sub i32 %r128, 48
  store i32 %r129, ptr @num, align 4
  br label %bb19

bb21:                                             ; preds = %bb19
  %r130 = load i32, ptr @TOKEN_NUM, align 4
  store i32 %r130, ptr @cur_token, align 4
  br label %bb18

bb17:                                             ; preds = %bb15
  %r131 = load i32, ptr @last_char, align 4
  store i32 %r131, ptr @other, align 4
  call void @next_char()
  %r132 = load i32, ptr @TOKEN_OTHER, align 4
  store i32 %r132, ptr @cur_token, align 4
  br label %bb18

bb18:                                             ; preds = %bb17, %bb21
  %r133 = load i32, ptr @cur_token, align 4
  ret i32 %r133
}

define i32 @panic() {
bb22:
  call void @putch(i32 112)
  call void @putch(i32 97)
  call void @putch(i32 110)
  call void @putch(i32 105)
  call void @putch(i32 99)
  call void @putch(i32 33)
  call void @putch(i32 10)
  %r134 = sub i32 0, 1
  ret i32 %r134
}

define i32 @get_op_prec(i32 %r135) {
bb23:
  %r136 = alloca i32, align 4
  store i32 %r135, ptr %r136, align 4
  %r137 = load i32, ptr %r136, align 4
  %r138 = icmp eq i32 %r137, 43
  br i1 %r138, label %bb24, label %bb26

bb26:                                             ; preds = %bb23
  %r139 = load i32, ptr %r136, align 4
  %r140 = icmp eq i32 %r139, 45
  br i1 %r140, label %bb24, label %bb25

bb24:                                             ; preds = %bb26, %bb23
  ret i32 10

0:                                                ; No predecessors!
  br label %bb25

bb25:                                             ; preds = %0, %bb26
  %r141 = load i32, ptr %r136, align 4
  %r142 = icmp eq i32 %r141, 42
  br i1 %r142, label %bb27, label %bb30

bb30:                                             ; preds = %bb25
  %r143 = load i32, ptr %r136, align 4
  %r144 = icmp eq i32 %r143, 47
  br i1 %r144, label %bb27, label %bb29

bb29:                                             ; preds = %bb30
  %r145 = load i32, ptr %r136, align 4
  %r146 = icmp eq i32 %r145, 37
  br i1 %r146, label %bb27, label %bb28

bb27:                                             ; preds = %bb29, %bb30, %bb25
  ret i32 20

1:                                                ; No predecessors!
  br label %bb28

bb28:                                             ; preds = %1, %bb29
  ret i32 0
}

define void @stack_push(ptr %r147, i32 %r148) {
bb31:
  %r149 = alloca i32, align 4
  store i32 %r148, ptr %r149, align 4
  %r150 = getelementptr i32, ptr %r147, i32 0
  %r151 = getelementptr i32, ptr %r147, i32 0
  %r152 = load i32, ptr %r151, align 4
  %r153 = add i32 %r152, 1
  store i32 %r153, ptr %r150, align 4
  %r154 = alloca i32, align 4
  %r155 = getelementptr i32, ptr %r147, i32 0
  %r156 = load i32, ptr %r155, align 4
  store i32 %r156, ptr %r154, align 4
  %r157 = load i32, ptr %r154, align 4
  %r158 = getelementptr i32, ptr %r147, i32 %r157
  %r159 = load i32, ptr %r149, align 4
  store i32 %r159, ptr %r158, align 4
  ret void
}

define i32 @stack_pop(ptr %r160) {
bb32:
  %r161 = alloca i32, align 4
  %r162 = getelementptr i32, ptr %r160, i32 0
  %r163 = load i32, ptr %r162, align 4
  store i32 %r163, ptr %r161, align 4
  %r164 = alloca i32, align 4
  %r165 = load i32, ptr %r161, align 4
  %r166 = getelementptr i32, ptr %r160, i32 %r165
  %r167 = load i32, ptr %r166, align 4
  store i32 %r167, ptr %r164, align 4
  %r168 = getelementptr i32, ptr %r160, i32 0
  %r169 = getelementptr i32, ptr %r160, i32 0
  %r170 = load i32, ptr %r169, align 4
  %r171 = sub i32 %r170, 1
  store i32 %r171, ptr %r168, align 4
  %r172 = load i32, ptr %r164, align 4
  ret i32 %r172
}

define i32 @stack_peek(ptr %r173) {
bb33:
  %r174 = alloca i32, align 4
  %r175 = getelementptr i32, ptr %r173, i32 0
  %r176 = load i32, ptr %r175, align 4
  store i32 %r176, ptr %r174, align 4
  %r177 = load i32, ptr %r174, align 4
  %r178 = getelementptr i32, ptr %r173, i32 %r177
  %r179 = load i32, ptr %r178, align 4
  ret i32 %r179
}

define i32 @stack_size(ptr %r180) {
bb34:
  %r181 = getelementptr i32, ptr %r180, i32 0
  %r182 = load i32, ptr %r181, align 4
  ret i32 %r182
}

define i32 @mod(i32 %r183, i32 %r185) {
bb35:
  %r184 = alloca i32, align 4
  store i32 %r183, ptr %r184, align 4
  %r186 = alloca i32, align 4
  store i32 %r185, ptr %r186, align 4
  %r187 = load i32, ptr %r184, align 4
  %r188 = load i32, ptr %r184, align 4
  %r189 = load i32, ptr %r186, align 4
  %r190 = sdiv i32 %r188, %r189
  %r191 = load i32, ptr %r186, align 4
  %r192 = mul i32 %r190, %r191
  %r193 = sub i32 %r187, %r192
  ret i32 %r193
}

define i32 @eval_op(i32 %r194, i32 %r196, i32 %r198) {
bb36:
  %r195 = alloca i32, align 4
  store i32 %r194, ptr %r195, align 4
  %r197 = alloca i32, align 4
  store i32 %r196, ptr %r197, align 4
  %r199 = alloca i32, align 4
  store i32 %r198, ptr %r199, align 4
  %r200 = load i32, ptr %r195, align 4
  %r201 = icmp eq i32 %r200, 43
  br i1 %r201, label %bb37, label %bb38

bb37:                                             ; preds = %bb36
  %r202 = load i32, ptr %r197, align 4
  %r203 = load i32, ptr %r199, align 4
  %r204 = add i32 %r202, %r203
  ret i32 %r204

0:                                                ; No predecessors!
  br label %bb38

bb38:                                             ; preds = %0, %bb36
  %r205 = load i32, ptr %r195, align 4
  %r206 = icmp eq i32 %r205, 45
  br i1 %r206, label %bb39, label %bb40

bb39:                                             ; preds = %bb38
  %r207 = load i32, ptr %r197, align 4
  %r208 = load i32, ptr %r199, align 4
  %r209 = sub i32 %r207, %r208
  ret i32 %r209

1:                                                ; No predecessors!
  br label %bb40

bb40:                                             ; preds = %1, %bb38
  %r210 = load i32, ptr %r195, align 4
  %r211 = icmp eq i32 %r210, 42
  br i1 %r211, label %bb41, label %bb42

bb41:                                             ; preds = %bb40
  %r212 = load i32, ptr %r197, align 4
  %r213 = load i32, ptr %r199, align 4
  %r214 = mul i32 %r212, %r213
  ret i32 %r214

2:                                                ; No predecessors!
  br label %bb42

bb42:                                             ; preds = %2, %bb40
  %r215 = load i32, ptr %r195, align 4
  %r216 = icmp eq i32 %r215, 47
  br i1 %r216, label %bb43, label %bb44

bb43:                                             ; preds = %bb42
  %r217 = load i32, ptr %r197, align 4
  %r218 = load i32, ptr %r199, align 4
  %r219 = sdiv i32 %r217, %r218
  ret i32 %r219

3:                                                ; No predecessors!
  br label %bb44

bb44:                                             ; preds = %3, %bb42
  %r220 = load i32, ptr %r195, align 4
  %r221 = icmp eq i32 %r220, 37
  br i1 %r221, label %bb45, label %bb46

bb45:                                             ; preds = %bb44
  %r222 = load i32, ptr %r197, align 4
  %r223 = load i32, ptr %r199, align 4
  %r224 = call i32 @mod(i32 %r222, i32 %r223)
  ret i32 %r224

4:                                                ; No predecessors!
  br label %bb46

bb46:                                             ; preds = %4, %bb44
  ret i32 0
}

define i32 @eval() {
bb47:
  %r278 = alloca i32, align 4
  %r276 = alloca i32, align 4
  %r274 = alloca i32, align 4
  %r260 = alloca i32, align 4
  %r258 = alloca i32, align 4
  %r256 = alloca i32, align 4
  %r244 = alloca i32, align 4
  %r225 = alloca [256 x i32], align 4
  %r226 = alloca [256 x i32], align 4
  %r227 = alloca i32, align 4
  store i32 0, ptr %r227, align 4
  br label %bb48

bb48:                                             ; preds = %bb49, %bb47
  %r228 = load i32, ptr %r227, align 4
  %r229 = icmp slt i32 %r228, 256
  br i1 %r229, label %bb49, label %bb50

bb49:                                             ; preds = %bb48
  %r230 = load i32, ptr %r227, align 4
  %r231 = getelementptr [256 x i32], ptr %r225, i32 0, i32 %r230
  store i32 0, ptr %r231, align 4
  %r232 = load i32, ptr %r227, align 4
  %r233 = getelementptr [256 x i32], ptr %r226, i32 0, i32 %r232
  store i32 0, ptr %r233, align 4
  %r234 = load i32, ptr %r227, align 4
  %r235 = add i32 %r234, 1
  store i32 %r235, ptr %r227, align 4
  br label %bb48

bb50:                                             ; preds = %bb48
  %r236 = load i32, ptr @cur_token, align 4
  %r237 = load i32, ptr @TOKEN_NUM, align 4
  %r238 = icmp ne i32 %r236, %r237
  br i1 %r238, label %bb51, label %bb52

bb51:                                             ; preds = %bb50
  %r239 = call i32 @panic()
  ret i32 %r239

0:                                                ; No predecessors!
  br label %bb52

bb52:                                             ; preds = %0, %bb50
  %r240 = load i32, ptr @num, align 4
  call void @stack_push(ptr %r225, i32 %r240)
  call void @next_token()
  br label %bb53

bb53:                                             ; preds = %bb63, %bb52
  %r241 = load i32, ptr @cur_token, align 4
  %r242 = load i32, ptr @TOKEN_OTHER, align 4
  %r243 = icmp eq i32 %r241, %r242
  br i1 %r243, label %bb54, label %bb55

bb54:                                             ; preds = %bb53
  %r245 = load i32, ptr @other, align 4
  store i32 %r245, ptr %r244, align 4
  %r246 = load i32, ptr %r244, align 4
  %r247 = call i32 @get_op_prec(i32 %r246)
  %r248 = icmp eq i32 %r247, 0
  br i1 %r248, label %bb56, label %bb57

bb56:                                             ; preds = %bb54
  br label %bb55

1:                                                ; No predecessors!
  br label %bb57

bb57:                                             ; preds = %1, %bb54
  call void @next_token()
  br label %bb58

bb58:                                             ; preds = %bb59, %bb57
  %r249 = call i32 @stack_size(ptr %r226)
  %r250 = icmp ne i32 %r249, 0
  br i1 %r250, label %bb61, label %bb60

bb61:                                             ; preds = %bb58
  %r251 = call i32 @stack_peek(ptr %r226)
  %r252 = call i32 @get_op_prec(i32 %r251)
  %r253 = load i32, ptr %r244, align 4
  %r254 = call i32 @get_op_prec(i32 %r253)
  %r255 = icmp sge i32 %r252, %r254
  br i1 %r255, label %bb59, label %bb60

bb59:                                             ; preds = %bb61
  %r257 = call i32 @stack_pop(ptr %r226)
  store i32 %r257, ptr %r256, align 4
  %r259 = call i32 @stack_pop(ptr %r225)
  store i32 %r259, ptr %r258, align 4
  %r261 = call i32 @stack_pop(ptr %r225)
  store i32 %r261, ptr %r260, align 4
  %r262 = load i32, ptr %r256, align 4
  %r263 = load i32, ptr %r260, align 4
  %r264 = load i32, ptr %r258, align 4
  %r265 = call i32 @eval_op(i32 %r262, i32 %r263, i32 %r264)
  call void @stack_push(ptr %r225, i32 %r265)
  br label %bb58

bb60:                                             ; preds = %bb61, %bb58
  %r266 = load i32, ptr %r244, align 4
  call void @stack_push(ptr %r226, i32 %r266)
  %r267 = load i32, ptr @cur_token, align 4
  %r268 = load i32, ptr @TOKEN_NUM, align 4
  %r269 = icmp ne i32 %r267, %r268
  br i1 %r269, label %bb62, label %bb63

bb62:                                             ; preds = %bb60
  %r270 = call i32 @panic()
  ret i32 %r270

2:                                                ; No predecessors!
  br label %bb63

bb63:                                             ; preds = %2, %bb60
  %r271 = load i32, ptr @num, align 4
  call void @stack_push(ptr %r225, i32 %r271)
  call void @next_token()
  br label %bb53

bb55:                                             ; preds = %bb56, %bb53
  call void @next_token()
  br label %bb64

bb64:                                             ; preds = %bb65, %bb55
  %r272 = call i32 @stack_size(ptr %r226)
  %r273 = icmp ne i32 %r272, 0
  br i1 %r273, label %bb65, label %bb66

bb65:                                             ; preds = %bb64
  %r275 = call i32 @stack_pop(ptr %r226)
  store i32 %r275, ptr %r274, align 4
  %r277 = call i32 @stack_pop(ptr %r225)
  store i32 %r277, ptr %r276, align 4
  %r279 = call i32 @stack_pop(ptr %r225)
  store i32 %r279, ptr %r278, align 4
  %r280 = load i32, ptr %r274, align 4
  %r281 = load i32, ptr %r278, align 4
  %r282 = load i32, ptr %r276, align 4
  %r283 = call i32 @eval_op(i32 %r280, i32 %r281, i32 %r282)
  call void @stack_push(ptr %r225, i32 %r283)
  br label %bb64

bb66:                                             ; preds = %bb64
  %r284 = call i32 @stack_peek(ptr %r225)
  ret i32 %r284
}

define i32 @main() {
bb67:
  %r285 = alloca i32, align 4
  %r286 = call i32 @getint()
  store i32 %r286, ptr %r285, align 4
  call void @getch()
  call void @next_token()
  br label %bb68

bb68:                                             ; preds = %bb69, %bb67
  %r287 = load i32, ptr %r285, align 4
  %r288 = icmp ne i32 %r287, 0
  br i1 %r288, label %bb69, label %bb70

bb69:                                             ; preds = %bb68
  %r289 = call i32 @eval()
  call void @putint(i32 %r289)
  call void @putch(i32 10)
  %r290 = load i32, ptr %r285, align 4
  %r291 = sub i32 %r290, 1
  store i32 %r291, ptr %r285, align 4
  br label %bb68

bb70:                                             ; preds = %bb68
  ret i32 0
}

; Function Attrs: noinline nounwind optnone ssp uwtable(sync)
define void @before_main() #0 {
  %1 = alloca i32, align 4
  store i32 0, ptr %1, align 4
  br label %2

2:                                                ; preds = %18, %0
  %3 = load i32, ptr %1, align 4
  %4 = icmp slt i32 %3, 1024
  br i1 %4, label %5, label %21

5:                                                ; preds = %2
  %6 = load i32, ptr %1, align 4
  %7 = sext i32 %6 to i64
  %8 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %7
  store i32 0, ptr %8, align 4
  %9 = load i32, ptr %1, align 4
  %10 = sext i32 %9 to i64
  %11 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %10
  store i32 0, ptr %11, align 4
  %12 = load i32, ptr %1, align 4
  %13 = sext i32 %12 to i64
  %14 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %13
  store i32 0, ptr %14, align 4
  %15 = load i32, ptr %1, align 4
  %16 = sext i32 %15 to i64
  %17 = getelementptr inbounds [1024 x i32], ptr @_sysy_h, i64 0, i64 %16
  store i32 0, ptr %17, align 4
  br label %18

18:                                               ; preds = %5
  %19 = load i32, ptr %1, align 4
  %20 = add nsw i32 %19, 1
  store i32 %20, ptr %1, align 4
  br label %2, !llvm.loop !5

21:                                               ; preds = %2
  store i32 1, ptr @_sysy_idx, align 4
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable(sync)
define internal void @__GLOBAL_init_65535() #1 section "__TEXT,__StaticInit,regular,pure_instructions" {
  %1 = call i32 @__cxa_atexit(ptr @after_main, ptr null, ptr @__dso_handle) #2
  ret void
}

; Function Attrs: noinline nounwind optnone ssp uwtable(sync)
define void @after_main() #0 {
  %1 = alloca i32, align 4
  store i32 1, ptr %1, align 4
  br label %2

2:                                                ; preds = %63, %0
  %3 = load i32, ptr %1, align 4
  %4 = load i32, ptr @_sysy_idx, align 4
  %5 = icmp slt i32 %3, %4
  br i1 %5, label %6, label %66

6:                                                ; preds = %2
  %7 = load ptr, ptr @__stderrp, align 8
  %8 = load i32, ptr %1, align 4
  %9 = sext i32 %8 to i64
  %10 = getelementptr inbounds [1024 x i32], ptr @_sysy_l1, i64 0, i64 %9
  %11 = load i32, ptr %10, align 4
  %12 = load i32, ptr %1, align 4
  %13 = sext i32 %12 to i64
  %14 = getelementptr inbounds [1024 x i32], ptr @_sysy_l2, i64 0, i64 %13
  %15 = load i32, ptr %14, align 4
  %16 = load i32, ptr %1, align 4
  %17 = sext i32 %16 to i64
  %18 = getelementptr inbounds [1024 x i32], ptr @_sysy_h, i64 0, i64 %17
  %19 = load i32, ptr %18, align 4
  %20 = load i32, ptr %1, align 4
  %21 = sext i32 %20 to i64
  %22 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %21
  %23 = load i32, ptr %22, align 4
  %24 = load i32, ptr %1, align 4
  %25 = sext i32 %24 to i64
  %26 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %25
  %27 = load i32, ptr %26, align 4
  %28 = load i32, ptr %1, align 4
  %29 = sext i32 %28 to i64
  %30 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %29
  %31 = load i32, ptr %30, align 4
  %32 = call i32 (ptr, ptr, ...) @fprintf(ptr noundef %7, ptr noundef @.str.5, i32 noundef %11, i32 noundef %15, i32 noundef %19, i32 noundef %23, i32 noundef %27, i32 noundef %31)
  %33 = load i32, ptr %1, align 4
  %34 = sext i32 %33 to i64
  %35 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %34
  %36 = load i32, ptr %35, align 4
  %37 = load i32, ptr @_sysy_us, align 4
  %38 = add nsw i32 %37, %36
  store i32 %38, ptr @_sysy_us, align 4
  %39 = load i32, ptr %1, align 4
  %40 = sext i32 %39 to i64
  %41 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %40
  %42 = load i32, ptr %41, align 4
  %43 = load i32, ptr @_sysy_s, align 4
  %44 = add nsw i32 %43, %42
  store i32 %44, ptr @_sysy_s, align 4
  %45 = load i32, ptr @_sysy_us, align 4
  %46 = srem i32 %45, 1000000
  store i32 %46, ptr @_sysy_us, align 4
  %47 = load i32, ptr %1, align 4
  %48 = sext i32 %47 to i64
  %49 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %48
  %50 = load i32, ptr %49, align 4
  %51 = load i32, ptr @_sysy_m, align 4
  %52 = add nsw i32 %51, %50
  store i32 %52, ptr @_sysy_m, align 4
  %53 = load i32, ptr @_sysy_s, align 4
  %54 = srem i32 %53, 60
  store i32 %54, ptr @_sysy_s, align 4
  %55 = load i32, ptr %1, align 4
  %56 = sext i32 %55 to i64
  %57 = getelementptr inbounds [1024 x i32], ptr @_sysy_h, i64 0, i64 %56
  %58 = load i32, ptr %57, align 4
  %59 = load i32, ptr @_sysy_h, align 4
  %60 = add nsw i32 %59, %58
  store i32 %60, ptr @_sysy_h, align 4
  %61 = load i32, ptr @_sysy_m, align 4
  %62 = srem i32 %61, 60
  store i32 %62, ptr @_sysy_m, align 4
  br label %63

63:                                               ; preds = %6
  %64 = load i32, ptr %1, align 4
  %65 = add nsw i32 %64, 1
  store i32 %65, ptr %1, align 4
  br label %2, !llvm.loop !7

66:                                               ; preds = %2
  %67 = load ptr, ptr @__stderrp, align 8
  %68 = load i32, ptr @_sysy_h, align 4
  %69 = load i32, ptr @_sysy_m, align 4
  %70 = load i32, ptr @_sysy_s, align 4
  %71 = load i32, ptr @_sysy_us, align 4
  %72 = call i32 (ptr, ptr, ...) @fprintf(ptr noundef %67, ptr noundef @.str.6, i32 noundef %68, i32 noundef %69, i32 noundef %70, i32 noundef %71)
  ret void
}

; Function Attrs: nounwind
declare i32 @__cxa_atexit(ptr, ptr, ptr) #2

declare i32 @fprintf(ptr noundef, ptr noundef, ...) #3

; Function Attrs: noinline nounwind optnone ssp uwtable(sync)
define i32 @getint() #0 {
  %1 = alloca i32, align 4
  %2 = call i32 (ptr, ...) @scanf(ptr noundef @.str, ptr noundef %1)
  %3 = load i32, ptr %1, align 4
  ret i32 %3
}

declare i32 @scanf(ptr noundef, ...) #3

; Function Attrs: noinline nounwind optnone ssp uwtable(sync)
define i32 @getch() #0 {
  %1 = alloca i8, align 1
  %2 = call i32 (ptr, ...) @scanf(ptr noundef @.str.1, ptr noundef %1)
  %3 = load i8, ptr %1, align 1
  %4 = sext i8 %3 to i32
  ret i32 %4
}

; Function Attrs: noinline nounwind optnone ssp uwtable(sync)
define void @putint(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  %3 = load i32, ptr %2, align 4
  %4 = call i32 (ptr, ...) @printf(ptr noundef @.str, i32 noundef %3)
  ret void
}

declare i32 @printf(ptr noundef, ...) #3

; Function Attrs: noinline nounwind optnone ssp uwtable(sync)
define void @putch(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  %3 = load i32, ptr %2, align 4
  %4 = call i32 (ptr, ...) @printf(ptr noundef @.str.1, i32 noundef %3)
  ret void
}

; Function Attrs: noinline nounwind optnone ssp uwtable(sync)
define void @putarray(i32 noundef %0, ptr noundef %1) #0 {
  %3 = alloca i32, align 4
  %4 = alloca ptr, align 8
  %5 = alloca i32, align 4
  store i32 %0, ptr %3, align 4
  store ptr %1, ptr %4, align 8
  %6 = load i32, ptr %3, align 4
  %7 = call i32 (ptr, ...) @printf(ptr noundef @.str.2, i32 noundef %6)
  store i32 0, ptr %5, align 4
  br label %8

8:                                                ; preds = %19, %2
  %9 = load i32, ptr %5, align 4
  %10 = load i32, ptr %3, align 4
  %11 = icmp slt i32 %9, %10
  br i1 %11, label %12, label %22

12:                                               ; preds = %8
  %13 = load ptr, ptr %4, align 8
  %14 = load i32, ptr %5, align 4
  %15 = sext i32 %14 to i64
  %16 = getelementptr inbounds i32, ptr %13, i64 %15
  %17 = load i32, ptr %16, align 4
  %18 = call i32 (ptr, ...) @printf(ptr noundef @.str.3, i32 noundef %17)
  br label %19

19:                                               ; preds = %12
  %20 = load i32, ptr %5, align 4
  %21 = add nsw i32 %20, 1
  store i32 %21, ptr %5, align 4
  br label %8, !llvm.loop !8

22:                                               ; preds = %8
  %23 = call i32 (ptr, ...) @printf(ptr noundef @.str.4)
  ret void
}

; Function Attrs: noinline nounwind optnone ssp uwtable(sync)
define void @_sysy_starttime(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  %3 = load i32, ptr %2, align 4
  %4 = load i32, ptr @_sysy_idx, align 4
  %5 = sext i32 %4 to i64
  %6 = getelementptr inbounds [1024 x i32], ptr @_sysy_l1, i64 0, i64 %5
  store i32 %3, ptr %6, align 4
  %7 = call i32 @gettimeofday(ptr noundef @_sysy_start, ptr noundef null)
  ret void
}

declare i32 @gettimeofday(ptr noundef, ptr noundef) #3

; Function Attrs: noinline nounwind optnone ssp uwtable(sync)
define void @_sysy_stoptime(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  %3 = call i32 @gettimeofday(ptr noundef @_sysy_end, ptr noundef null)
  %4 = load i32, ptr %2, align 4
  %5 = load i32, ptr @_sysy_idx, align 4
  %6 = sext i32 %5 to i64
  %7 = getelementptr inbounds [1024 x i32], ptr @_sysy_l2, i64 0, i64 %6
  store i32 %4, ptr %7, align 4
  %8 = load i64, ptr @_sysy_end, align 8
  %9 = load i64, ptr @_sysy_start, align 8
  %10 = sub nsw i64 %8, %9
  %11 = mul nsw i64 1000000, %10
  %12 = load i32, ptr getelementptr inbounds (%struct.timeval, ptr @_sysy_end, i32 0, i32 1), align 8
  %13 = sext i32 %12 to i64
  %14 = add nsw i64 %11, %13
  %15 = load i32, ptr getelementptr inbounds (%struct.timeval, ptr @_sysy_start, i32 0, i32 1), align 8
  %16 = sext i32 %15 to i64
  %17 = sub nsw i64 %14, %16
  %18 = load i32, ptr @_sysy_idx, align 4
  %19 = sext i32 %18 to i64
  %20 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %19
  %21 = load i32, ptr %20, align 4
  %22 = sext i32 %21 to i64
  %23 = add nsw i64 %22, %17
  %24 = trunc i64 %23 to i32
  store i32 %24, ptr %20, align 4
  %25 = load i32, ptr @_sysy_idx, align 4
  %26 = sext i32 %25 to i64
  %27 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %26
  %28 = load i32, ptr %27, align 4
  %29 = sdiv i32 %28, 1000000
  %30 = load i32, ptr @_sysy_idx, align 4
  %31 = sext i32 %30 to i64
  %32 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %31
  %33 = load i32, ptr %32, align 4
  %34 = add nsw i32 %33, %29
  store i32 %34, ptr %32, align 4
  %35 = load i32, ptr @_sysy_idx, align 4
  %36 = sext i32 %35 to i64
  %37 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %36
  %38 = load i32, ptr %37, align 4
  %39 = srem i32 %38, 1000000
  store i32 %39, ptr %37, align 4
  %40 = load i32, ptr @_sysy_idx, align 4
  %41 = sext i32 %40 to i64
  %42 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %41
  %43 = load i32, ptr %42, align 4
  %44 = sdiv i32 %43, 60
  %45 = load i32, ptr @_sysy_idx, align 4
  %46 = sext i32 %45 to i64
  %47 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %46
  %48 = load i32, ptr %47, align 4
  %49 = add nsw i32 %48, %44
  store i32 %49, ptr %47, align 4
  %50 = load i32, ptr @_sysy_idx, align 4
  %51 = sext i32 %50 to i64
  %52 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %51
  %53 = load i32, ptr %52, align 4
  %54 = srem i32 %53, 60
  store i32 %54, ptr %52, align 4
  %55 = load i32, ptr @_sysy_idx, align 4
  %56 = sext i32 %55 to i64
  %57 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %56
  %58 = load i32, ptr %57, align 4
  %59 = sdiv i32 %58, 60
  %60 = load i32, ptr @_sysy_idx, align 4
  %61 = sext i32 %60 to i64
  %62 = getelementptr inbounds [1024 x i32], ptr @_sysy_h, i64 0, i64 %61
  %63 = load i32, ptr %62, align 4
  %64 = add nsw i32 %63, %59
  store i32 %64, ptr %62, align 4
  %65 = load i32, ptr @_sysy_idx, align 4
  %66 = sext i32 %65 to i64
  %67 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %66
  %68 = load i32, ptr %67, align 4
  %69 = srem i32 %68, 60
  store i32 %69, ptr %67, align 4
  %70 = load i32, ptr @_sysy_idx, align 4
  %71 = add nsw i32 %70, 1
  store i32 %71, ptr @_sysy_idx, align 4
  ret void
}

attributes #0 = { noinline nounwind optnone ssp uwtable(sync) "frame-pointer"="non-leaf" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="apple-m1" "target-features"="+aes,+complxnum,+crc,+dotprod,+fp-armv8,+fp16fml,+fullfp16,+jsconv,+lse,+neon,+pauth,+ras,+rcpc,+rdm,+sha2,+sha3,+v8.1a,+v8.2a,+v8.3a,+v8.4a,+v8.5a,+v8a,+zcm,+zcz" }
attributes #1 = { noinline nounwind ssp uwtable(sync) "frame-pointer"="non-leaf" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="apple-m1" "target-features"="+aes,+complxnum,+crc,+dotprod,+fp-armv8,+fp16fml,+fullfp16,+jsconv,+lse,+neon,+pauth,+ras,+rcpc,+rdm,+sha2,+sha3,+v8.1a,+v8.2a,+v8.3a,+v8.4a,+v8.5a,+v8a,+zcm,+zcz" }
attributes #2 = { nounwind }
attributes #3 = { "frame-pointer"="non-leaf" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="apple-m1" "target-features"="+aes,+complxnum,+crc,+dotprod,+fp-armv8,+fp16fml,+fullfp16,+jsconv,+lse,+neon,+pauth,+ras,+rcpc,+rdm,+sha2,+sha3,+v8.1a,+v8.2a,+v8.3a,+v8.4a,+v8.5a,+v8a,+zcm,+zcz" }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1, !2, !3, !4}

!0 = !{!"Homebrew clang version 18.1.8"}
!1 = !{i32 1, !"wchar_size", i32 4}
!2 = !{i32 8, !"PIC Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{i32 7, !"frame-pointer", i32 1}
!5 = distinct !{!5, !6}
!6 = !{!"llvm.loop.mustprogress"}
!7 = distinct !{!7, !6}
!8 = distinct !{!8, !6}
