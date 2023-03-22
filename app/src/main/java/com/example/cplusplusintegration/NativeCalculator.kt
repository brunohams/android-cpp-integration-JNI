package com.example.cplusplusintegration

import androidx.lifecycle.DefaultLifecycleObserver
import androidx.lifecycle.LifecycleOwner

interface Calculator {
    fun sum(first: Int, second: Int): Int
    fun minus(first: Int, second: Int): Int
    fun times(first: Int, second: Int): Int
    fun divide(first: Int, second: Int): Int
}

class NativeCalculator : Calculator, DefaultLifecycleObserver {
    private var calculatorHandle: Long = 0
    private val calculatorMutex = Object()
    private external fun create(): Long
    private external fun delete(calculatorHandle: Long)

    // Calculator external functions
    private external fun sum(calculatorHandle: Long, first: Int, second: Int): Int
    private external fun minus(calculatorHandle: Long, first: Int, second: Int): Int
    private external fun times(calculatorHandle: Long, first: Int, second: Int): Int
    private external fun divide(calculatorHandle: Long, first: Int, second: Int): Int

    companion object {
        init {
            System.loadLibrary("cplusplusintegration")
        }
    }

    override fun onResume(owner: LifecycleOwner) {
        super.onResume(owner)

        synchronized(calculatorMutex) {
            createNativeHandleIfNotExists()
        }
    }

    override fun onPause(owner: LifecycleOwner) {
        super.onPause(owner)

        synchronized(calculatorMutex) {
            if (calculatorHandle == 0L) {
                return
            }
            delete(calculatorHandle)
            calculatorHandle = 0L
        }
    }

    private fun createNativeHandleIfNotExists() {
        if (calculatorHandle != 0L) {
            return
        }
        calculatorHandle = create()
    }

    override fun sum(first: Int, second: Int): Int {
        synchronized(calculatorMutex) {
            createNativeHandleIfNotExists()
            return sum(calculatorHandle, first, second)
        }
    }

    override fun minus(first: Int, second: Int): Int {
        synchronized(calculatorMutex) {
            createNativeHandleIfNotExists()
            return minus(calculatorHandle, first, second)
        }
    }

    override fun times(first: Int, second: Int): Int {
        synchronized(calculatorMutex) {
            createNativeHandleIfNotExists()
            return times(calculatorHandle, first, second)
        }
    }

    override fun divide(first: Int, second: Int): Int {
        synchronized(calculatorMutex) {
            createNativeHandleIfNotExists()
            return divide(calculatorHandle, first, second)
        }
    }

}