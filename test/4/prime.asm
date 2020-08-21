00010148 <main>:
   10148:	fe010113          	addi	sp,sp,-32
   1014c:	00112e23          	sw	ra,28(sp)
   10150:	00812c23          	sw	s0,24(sp)
   10154:	02010413          	addi	s0,sp,32
   10158:	06500793          	li	a5,101
   1015c:	fef42623          	sw	a5,-20(s0)
   10160:	fec42503          	lw	a0,-20(s0)
   10164:	020000ef          	jal	10184 <is_prime>
   10168:	fea42423          	sw	a0,-24(s0)
   1016c:	fe842783          	lw	a5,-24(s0)
   10170:	00078513          	mv	a0,a5
   10174:	01c12083          	lw	ra,28(sp)
   10178:	01812403          	lw	s0,24(sp)
   1017c:	02010113          	addi	sp,sp,32
   10180:	00008067          	ret

00010184 <is_prime>:
   10184:	fd010113          	addi	sp,sp,-48
   10188:	02112623          	sw	ra,44(sp)
   1018c:	02812423          	sw	s0,40(sp)
   10190:	03010413          	addi	s0,sp,48
   10194:	fca42e23          	sw	a0,-36(s0)
   10198:	00200793          	li	a5,2
   1019c:	fef42623          	sw	a5,-20(s0)
   101a0:	0300006f          	j	101d0 <is_prime+0x4c>
   101a4:	fdc42783          	lw	a5,-36(s0)
   101a8:	fec42583          	lw	a1,-20(s0)
   101ac:	00078513          	mv	a0,a5
   101b0:	0d8000ef          	jal	10288 <__modsi3>
   101b4:	00050793          	mv	a5,a0
   101b8:	00079663          	bnez	a5,101c4 <is_prime+0x40>
   101bc:	fec42783          	lw	a5,-20(s0)
   101c0:	0300006f          	j	101f0 <is_prime+0x6c>
   101c4:	fec42783          	lw	a5,-20(s0)
   101c8:	00178793          	addi	a5,a5,1
   101cc:	fef42623          	sw	a5,-20(s0)
   101d0:	fdc42783          	lw	a5,-36(s0)
   101d4:	01f7d713          	srli	a4,a5,0x1f
   101d8:	00f707b3          	add	a5,a4,a5
   101dc:	4017d793          	srai	a5,a5,0x1
   101e0:	00078713          	mv	a4,a5
   101e4:	fec42783          	lw	a5,-20(s0)
   101e8:	fae7cee3          	blt	a5,a4,101a4 <is_prime+0x20>
   101ec:	2c300793          	li	a5,707
   101f0:	00078513          	mv	a0,a5
   101f4:	02c12083          	lw	ra,44(sp)
   101f8:	02812403          	lw	s0,40(sp)
   101fc:	03010113          	addi	sp,sp,48
   10200:	00008067          	ret

00010204 <__divsi3>:
   10204:	06054063          	bltz	a0,10264 <__umodsi3+0x10>
   10208:	0605c663          	bltz	a1,10274 <__umodsi3+0x20>

0001020c <__udivsi3>:
   1020c:	00058613          	mv	a2,a1
   10210:	00050593          	mv	a1,a0
   10214:	fff00513          	li	a0,-1
   10218:	02060c63          	beqz	a2,10250 <__udivsi3+0x44>
   1021c:	00100693          	li	a3,1
   10220:	00b67a63          	bleu	a1,a2,10234 <__udivsi3+0x28>
   10224:	00c05863          	blez	a2,10234 <__udivsi3+0x28>
   10228:	00161613          	slli	a2,a2,0x1
   1022c:	00169693          	slli	a3,a3,0x1
   10230:	feb66ae3          	bltu	a2,a1,10224 <__udivsi3+0x18>
   10234:	00000513          	li	a0,0
   10238:	00c5e663          	bltu	a1,a2,10244 <__udivsi3+0x38>
   1023c:	40c585b3          	sub	a1,a1,a2
   10240:	00d56533          	or	a0,a0,a3
   10244:	0016d693          	srli	a3,a3,0x1
   10248:	00165613          	srli	a2,a2,0x1
   1024c:	fe0696e3          	bnez	a3,10238 <__udivsi3+0x2c>
   10250:	00008067          	ret

00010254 <__umodsi3>:
   10254:	00008293          	mv	t0,ra
   10258:	fb5ff0ef          	jal	1020c <__udivsi3>
   1025c:	00058513          	mv	a0,a1
   10260:	00028067          	jr	t0
   10264:	40a00533          	neg	a0,a0
   10268:	0005d863          	bgez	a1,10278 <__umodsi3+0x24>
   1026c:	40b005b3          	neg	a1,a1
   10270:	f95ff06f          	j	10204 <__divsi3>
   10274:	40b005b3          	neg	a1,a1
   10278:	00008293          	mv	t0,ra
   1027c:	f89ff0ef          	jal	10204 <__divsi3>
   10280:	40a00533          	neg	a0,a0
   10284:	00028067          	jr	t0

00010288 <__modsi3>:
   10288:	00008293          	mv	t0,ra
   1028c:	0005ca63          	bltz	a1,102a0 <__modsi3+0x18>
   10290:	00054c63          	bltz	a0,102a8 <__modsi3+0x20>
   10294:	f79ff0ef          	jal	1020c <__udivsi3>
   10298:	00058513          	mv	a0,a1
   1029c:	00028067          	jr	t0
   102a0:	40b005b3          	neg	a1,a1
   102a4:	fe0558e3          	bgez	a0,10294 <__modsi3+0xc>
   102a8:	40a00533          	neg	a0,a0
   102ac:	f61ff0ef          	jal	1020c <__udivsi3>
   102b0:	40b00533          	neg	a0,a1
   102b4:	00028067          	jr	t0

